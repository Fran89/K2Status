#include "k2status.h"
#include "ui_k2status.h"

K2Status::K2Status(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::K2Status)
{
    //Draw Screen, Setup some Variables
    ui->setupUi(this);
    Cur = 0;
    Debug = false;
    ui->textBrowser->append("Debug mode is off");
    Start = false;
    UDPComm = true;
    Table = new QStandardItemModel(0,13);
    Table->setHorizontalHeaderItem(Tnet,new QStandardItem(QString("Network")));
    Table->setHorizontalHeaderItem(Tsta,new QStandardItem(QString("Station")));
    Table->setHorizontalHeaderItem(Tser,new QStandardItem(QString("Serial #")));
    Table->setHorizontalHeaderItem(Tvol,new QStandardItem(QString("Voltage")));
    Table->setHorizontalHeaderItem(Ttem,new QStandardItem(QString("Temperature")));
    Table->setHorizontalHeaderItem(Thws,new QStandardItem(QString("HW Status")));
    Table->setHorizontalHeaderItem(Tbts,new QStandardItem(QString("BT Status")));
    Table->setHorizontalHeaderItem(Tfac,new QStandardItem(QString("Fault Code")));
    Table->setHorizontalHeaderItem(Ttim,new QStandardItem(QString("Time")));
    Table->setHorizontalHeaderItem(Ttsc,new QStandardItem(QString("Time Src")));
    Table->setHorizontalHeaderItem(Tds1,new QStandardItem(QString("Disk 1")));
    Table->setHorizontalHeaderItem(Tds2,new QStandardItem(QString("Disk 2")));
    Table->setHorizontalHeaderItem(Tevt,new QStandardItem(QString("Events")));

    ui->tableView->setModel(Table);
    ui->statusBar->showMessage("Welcome to K2Status");
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);

    MessThr = new QThread;
    TimeThr = new QThread;
    MessThr->start();
    TimeThr->start();
    MessRcv = new MessageRcv;
    MessRcv->moveToThread(MessThr);
    ColTimer.start(500);
    ColTimer.moveToThread(TimeThr);

    connect(&ColTimer,SIGNAL(timeout()),this,SLOT(UpdateTimeColors()));
    connect(this,SIGNAL(start_listen(QTcpSocket*,Config*,bool)),
            MessRcv,SLOT(ListenMessage(QTcpSocket*,Config*,bool)));
    connect(MessRcv,SIGNAL(updatetxtbox(QString)),
            this,SLOT(tcpmsgtobox(QString)));
    connect(MessRcv,SIGNAL(ReturnMessage(QByteArray)),
            this,SLOT(has_read_tcp(QByteArray)));
    connect(this,SIGNAL(update_gview(QList<stninfo>)),
            &GV,SLOT(update_archive(QList<stninfo>)));

    QDir logs("logs");

    if( ! logs.exists() )
        logs.mkpath(".");


    ui->toolBar->addAction(QIcon(":/K2Status/icons/addcon.png"),"Add a Connection",this,SLOT(on_actionAdd_Connection_triggered()));
    ui->toolBar->addAction(QIcon(":/K2Status/icons/debug.png") , "Toggle Debug Mode", this, SLOT(on_actionDebug_Mode_triggered()));
}

K2Status::~K2Status()
{
    delete Table;
    delete ui;
}

void K2Status::Dialog_off(Config& TestC){
    ConfTest = TestC;
    // This is a socket for the when we accept the parameters in the Define
    // and Connect Dialog, as well as opening the
    ui->ToIP_2->setText(ConfTest.getSendIPQ());
    ui->ToPort->setText(ConfTest.getSendPortQ());
    UDPComm=ConfTest.Comm;

    if(UDPComm){
        ui->textBrowser->append("UDP Mode Selected");
        QHostAddress IPadr(ConfTest.getSendIPQ());
        udpSocket = new QUdpSocket(this);

        if (udpSocket->bind(IPadr,ConfTest.getSendPortI())){
            connect(udpSocket,SIGNAL(readyRead()),
                    this,SLOT(has_read_data()));
            ui->textBrowser->append("Program connected");
        }
        else
            ui->textBrowser->append("Did not connect");
        delete mDefineAndConnect;
    }
    else{
        ui->textBrowser->append("TCP Mode Selected");
        QHostAddress IPadr(ConfTest.getSendIPQ());
        tcpSocket = new QTcpSocket(this);
        tcpSocket->connectToHost(IPadr,ConfTest.getSendPortI());
        if (tcpSocket->waitForConnected()){
            ui->textBrowser->append("Program connected");
            emit start_listen(tcpSocket,&ConfTest,Debug);
        }
        delete mDefineAndConnect;
    }

}

void K2Status::on_actionAdd_Connection_triggered()
{
    // Create the Define and Connect Dialog, and connect the signal that it has ended to
    // the main window
    mDefineAndConnect = new DefineAndConnect();
    connect(mDefineAndConnect,SIGNAL(endingsig(Config&)),
            this,SLOT(Dialog_off(Config&)));
    mDefineAndConnect->show();
}

void K2Status::on_actionQuit_triggered()
{
    // Exit the Application
    QCoreApplication::quit();
}

void K2Status::has_read_data(){
    // To be executed if we have recieved a UDP Packet
    while (udpSocket->hasPendingDatagrams()) {
        // Declare EW Packet and some QByteArrays
        PACKET packet;
        QByteArray data;
        data.resize(udpSocket->pendingDatagramSize());

        // Get the Packet put the data in an Array
        udpSocket->readDatagram(data.data(),data.size());
        memcpy(&packet,data,data.size());

        parse_UDPpacket(packet,data);

        // Output some Info to the Screen
        if (Debug){
            QString str=data.data();
            ui->textBrowser->append(FileN);
            ui->textBrowser->append(str);
        }
    }
}

void K2Status::on_actionDebug_Mode_triggered(){
    stninfo temp, temp2;
    QList<stninfo> tmpl;
    temp.setup("AG02");
    temp.addstninfo(30,12.5);
    temp.addstninfo(45,12.8);
    temp.addstninfo(40,13.6);
    temp2.setup("AR02");
    temp2.addstninfo(28,12.7);
    temp2.addstninfo(32.4,12.9);
    temp2.addstninfo(28.8,13.2);
    tmpl.append(temp);
    tmpl.append(temp2);
    emit update_gview(tmpl);

    if (Debug == true){
        Debug = false;
        ui->textBrowser->append("Debug mode off");
    }
    else if (Debug == false){
        Debug = true;
        ui->textBrowser->append("Debug mode on");
    }
}

// Easily editable to take in just the messages.. eventually
void K2Status::parse_UDPpacket(PACKET packet, QByteArray data){

    //Debugging Info SETUP
    if(Debug) {
        FileN = QString("File-");
        QString FNum =QString::number(Cur);
        FileN.push_back(FNum);
        FileN.push_back(".txt");

        FileN2 = QString("RAW-");
        FileN2.push_back(FNum);

        file.setFileName(FileN);
        file2.setFileName(FileN2);

        out.setDevice(&file);
        out2.setDevice(&file2);

        file2.resize(0);
        file.resize(0);
        file2.open(QIODevice::Append);
        file.open(QIODevice::Append);

    }

    // Debugging Info
    if(Debug) {
        out << packet.msgInst << " "
            << packet.msgType << " "
            << packet.modId   << " "
            << packet.fragNum << "\n"
            << packet.msgSeqNum << " "
            << packet.lastOfMsg;
    }

    // If the Packet is Complete
    if (packet.lastOfMsg && packet.fragNum == 0 ) {

        // Declare a new K2infoPacket, put the Package payload bay in there
        MyK2Info = new K2infoPacket;
        memcpy(MyK2Info, &packet.text, data.size()-UDP_HDR);

        // Debug Info
        if(Debug) {
            time_t sent = (time_t) MyK2Info->k2info.epoch_sent;
            out << "\n=======\n"
                << MyK2Info->k2info.sta << " "
                << MyK2Info->k2info.net << " "
                << MyK2Info->k2info.data_type << " "
                << "Sent: " << asctime(gmtime(&sent));
        }

        // If it's a K2 regular status packet
        if(MyK2Info->k2info.data_type==2) {

            // Debug Info
            if (Debug){
                out << "K2 regular status packet \n"
                    << "Total Size of Packet: " << data.size()           << "\n"
                    << "Size of UDP Header: "   << UDP_HDR               << "\n"
                    << "Size of K2INFO Packet: "<< sizeof(K2INFO_HEADER) +
                                                   sizeof(STATUS_INFO)  << "\n"
                    << " Composed of a HEADER: "<< sizeof(K2INFO_HEADER)<< "\n"
                    << " Composed of a MESSAG: "<< sizeof(struct STATUS_INFO);
            }

            // Initialize Structures
            STATUS_INFO        *MyK2Stat;
            MyK2Head = new K2INFO_HEADER;
            MyK2Stat = new STATUS_INFO;

            // Extract Info and put it back into a data structure
            memcpy(MyK2Head,data.mid(UDP_HDR,sizeof(K2INFO_HEADER)).data(),sizeof(K2INFO_HEADER));
            memcpy(MyK2Stat,data.mid(sizeof(K2INFO_HEADER)+UDP_HDR).data(),sizeof(STATUS_INFO));
            // Finish Extraction

            // Update UI
            addK2Status(fetch_index(MyK2Head),MyK2Stat);


            // Debug Info
            if (Debug){
                time_t timevar, sentvar;
                int tempbat;//, index;
                double batv;//, diskfree;
                /*char tempchar, disk[2] = {'A', 'B'};
                unsigned short wtemp1, wtemp2;*/
                sentvar = (time_t) MyK2Head->epoch_sent;
                timevar = (time_t) (qFromBigEndian<quint32>(MyK2Stat->systemTime) + K2_TIME_CONV);
                tempbat = (int) MyK2Stat->batteryStatus;   // char, no need to swap
                batv = tempbat/10.0;
                if (tempbat < 0){
                    batv = -batv;
                }

                // To the ASCII FILE
                // First Line and TimeStaps
                out << "\n==== some info ===\n";
                out << MyK2Head->sta       << " "
                    << MyK2Head->net       << " "
                    << MyK2Head->data_type << "\n"
                    << "K2PSent time is "  << asctime(gmtime(&sentvar))
                    << "K2Time is "        << asctime(gmtime(&timevar));

                // Set Clock Source
                switch (MyK2Stat->clockSource)
                  {
                  case 0:
                    out << "Set from RTC\n";
                    break;
                  case 1:
                    out << "Set from Keyboard\n";
                    break;
                  case 2:
                    out << "Set from External Pulse\n";
                    break;
                  case 3:
                    out << "Set from Internal GPS\n";
                    break;
                  default:
                    out << "Set from (?)\n";
                  }

                // Set Serial Number
                out << "K2Serial Number: " << MyK2Stat->serialNumber << "\n";

                if (tempbat > 0) //K2 says battery voltage is zero when it is charging
                {
                    if(MyK2Stat->driveStatus)
                        out << "HW: OK ";
                    else
                        out << "HW: FAULT ";
                    out << "Battery: Not Charging\n";
                    out << "Battery: " << batv << " V\n";
                }
                else {
                    if(MyK2Stat->driveStatus)
                        out << "HW: OK ";
                    else
                        out << "HW: FAULT ";
                    out << "Battery: Charging\n";
                }
                out << "Events: " << qFromBigEndian<quint16>(MyK2Stat->events) << " "
                    << "Errors: " << qFromBigEndian<quint16>(MyK2Stat->recordingErrors) << "\n";

                // To the RAW FILE
                out2 << data;
            }

            // Destroy Structures
            delete[] MyK2Head;
            delete[] MyK2Stat;
        }

        // If its a K2 extended status packet v2
        if(MyK2Info->k2info.data_type==4) {

            // Debug Info
            if (Debug){
                out << "K2 extended status packet v2 \n"
                    << "Total Size of Packet: " << data.size()               << "\n"
                    << "Size of UDP Header: "   << UDP_HDR                   << "\n"
                    << "Size of K2INFO Packet: "<< sizeof(K2INFO_HEADER) +
                                                   sizeof(EXT2_STATUS_INFO)  << "\n"
                    << " Composed of a HEADER: "<< sizeof(K2INFO_HEADER)     << "\n"
                    << " Composed of a MESSAG: "<< sizeof(EXT2_STATUS_INFO);
            }

            // Initialize Structures
            EXT2_STATUS_INFO   *MyK2Stat2;
            MyK2Head  = new K2INFO_HEADER;
            MyK2Stat2 = new EXT2_STATUS_INFO;

            // Extract Info and put it back into a data structure
            memcpy(MyK2Head  ,data.mid(UDP_HDR,sizeof(K2INFO_HEADER)).data(),sizeof(K2INFO_HEADER));
            memcpy(MyK2Stat2 ,data.mid(sizeof(K2INFO_HEADER)+UDP_HDR).data(),sizeof(EXT2_STATUS_INFO));
            // Finish Extraction

            // Update UI
            addK2Status2(fetch_index(MyK2Head),MyK2Stat2);

            if(Debug){
                unsigned short us_dummy;
                unsigned long  ul_dummy;
                unsigned short fault;
                time_t timevar;

                // Packet Sent Time
                time_t sentvar;
                sentvar = (time_t) MyK2Head->epoch_sent;

                /* Last restart time */
                memcpy(&ul_dummy, ((char *)MyK2Stat2) + 2, sizeof(long));
                timevar = (time_t)(qFromBigEndian<quint32>(ul_dummy) + K2_TIME_CONV);

                // To the ASCII FILE
                out << "\n==== some info ===\n";
                out << MyK2Head->sta       << " "
                    << MyK2Head->net       << " "
                    << MyK2Head->data_type << "\n"
                    << "K2PSent time is "  << asctime(gmtime(&sentvar));
                out << "Temperature: "     << qFromBigEndian<quint16>(MyK2Stat2->temperature) /10
                                           << "." << qFromBigEndian<quint16>(MyK2Stat2->temperature) %10 << "\n";

                // Last Restart
                out << "Last Restart: " << asctime(gmtime(&timevar));
                switch (MyK2Stat2->clockSource)
                {
                case 0:
                  out << "From RTC";
                  break;
                case 1:
                  out << "From keyboard";
                  break;
                case 2:
                  out << "From External Pulse";
                  break;
                case 3:
                  out << "From Internal GPS";
                  break;
                default:
                  out << "From (?)";
                }

                /* Fault status */
                memcpy(&us_dummy, ((char *)MyK2Stat2) + 6, sizeof(short));
                fault = qFromBigEndian<quint16>(us_dummy);
                out << "\nK2 fault status: ";
                if (fault != (unsigned short)0)
                {
                    if (fault & FAULT_SYSTEM)
                      out << "bad parameters; \n";
                    if (fault & FAULT_FLASH)
                      out << "flash error; \n";
                    if (fault & FAULT_RAM)
                      out << "ram error at " <<
                              qFromBigEndian<quint32>(MyK2Stat2->lastRAMError)<<"\n";
                    if (fault & FAULT_PCMCIA)
                      out << "bad/missing PCMCIA; \n";
                    if (fault & FAULT_DSP)
                      out << "failed to load DSP; \n";
                    if (fault & FAULT_PARMBLK)
                      out << "param block CRC error; \n";
                    if (fault & FAULT_FLASH_MAINTENANCE)
                      out << "flash maintenance required;\n";
                  }
                else
                out << "OK";

                //To the RAW FILE
                out2 << data;
            }

            // Destroy Structures
            delete[] MyK2Head;
            delete[] MyK2Stat2;
        }

        // Delete K2infoPacket
        delete[] MyK2Info;
    }

    // If not it must be the super long Params Packet ... sigh
    if (packet.fragNum == 0 && !packet.lastOfMsg) {

        // Declare a new K2infoPacket, put the Package payload bay in there
        MyK2Info = new K2infoPacket;
        memcpy(MyK2Info, &packet.text, data.size()-UDP_HDR);

        // Debug Info
        if(Debug) {
            time_t sent = (time_t) MyK2Info->k2info.epoch_sent;
            out << "\n=======\n"
                << MyK2Info->k2info.sta       << " "
                << MyK2Info->k2info.net       << " "
                << MyK2Info->k2info.data_type << " "
                << "Sent: " << asctime(gmtime(&sent));

            out << "K2 Header Packet 1 of 2 \n"
                << "Total Size of Packet: " << data.size()           << "\n"
                << "Size of UDP Header: "   << UDP_HDR               << "\n"
                << " Contains : " << data.size()-UDP_HDR
                << " of " << sizeof(K2_HEADER) + sizeof(K2INFO_HEADER) << " bytes";
        }

        //Clear our Memory
        MyK2HDR.clear();

        // Declare a new K2HDR Array, put the Package payload in there
        MyK2HDR.resize(data.size()-UDP_HDR);
        memcpy(MyK2HDR.data(),data.mid(UDP_HDR),data.size()-UDP_HDR);

        //We Have begun
        Start = true;

        // Debug Info
        if(Debug){
            // To RAW FILE
            out2 << data;
        }

        // Destroy K2infoPacket
        delete[] MyK2Info;

    }

    // The continuation of the last Params Packet
    if (packet.fragNum == 1 && packet.lastOfMsg) {

        // Debug Info
        if(Debug) {
            out << "K2 Header Packet 2 of 2 \n"
                << "Total Size of Packet: " << data.size()             << "\n"
                << "Size of UDP Header: "   << UDP_HDR                 << "\n"
                << " Composed of a MESSAG: "<< data.size()-UDP_HDR     << "\n"
                << " Contains : " << data.size()-UDP_HDR
                << " of " << sizeof(K2_HEADER) + sizeof(K2INFO_HEADER) << " bytes";
        }

        if (Start == true) { //yes we did begin this is the continuation, (Remember to code in continuity ie check packet num)
            int nsize = data.size()-UDP_HDR;
            int csize = MyK2HDR.size();

            // Tack on the previous package Info
            MyK2HDR.resize(csize+nsize);
            MyK2HDR.append(data.mid(UDP_HDR).data());

            // Create a the K2INFO Header again and Initialize a new K2_HEADER Instance
            MyK2Head = new K2INFO_HEADER;
            K2_HEADER *MyK2HDS;
            MyK2HDS = new K2_HEADER;

            // Extract the information
            memcpy(MyK2Head,MyK2HDR.data(), sizeof(K2INFO_HEADER));
            memcpy(MyK2HDS,MyK2HDR.mid(sizeof(K2INFO_HEADER)).data(), sizeof(K2_HEADER));
            // Finish Extraction

            // Update UI
            addK2HeaderS(fetch_index(MyK2Head),MyK2HDS);

            // Debug Info
            if(Debug){

                short batt_voltx10;
                double batv;
                short temp,temp2;
                temp2 = (short)qFromBigEndian<quint16>(MyK2HDS->roParms.misc.temperature);
                time_t timevar1 = (time_t)(qFromBigEndian<quint32>(MyK2HDS->roParms.timing.gpsLastLockTime[0])
                        + K2_TIME_CONV);
                temp = (short)qFromBigEndian<quint32>( MyK2HDS->roParms.timing.gpsLastDrift[0]);
                batt_voltx10 = (signed short)qFromBigEndian<quint16>(MyK2HDS->roParms.misc.batteryVoltage);

                // To ASCII File
                out << "\n=====";
                out << "\nTemperature: " << temp2/10<<"."<<temp2%10 <<" deg C\n";
                out << "Last GPS lock: " << asctime(gmtime(&timevar1));
                out << "Drift: " << temp << "\n";

                /* Battery voltage is reported as negative when supplied from external *
                 * source. That's what we need here; internal battery voltage is       *
                 * reported in status block, above */

                if (batt_voltx10 < 0)
                {
                       batt_voltx10 = -batt_voltx10;
                       batv = batt_voltx10 / 10.0;
                       out << "External battery voltage: " << batv << "\n";
                }

                // To RAW file
                out2 << MyK2HDR;
            }

            delete[] MyK2Head;
            delete[] MyK2HDS;
            Start = false;
        }

        else if (Start == false){ // We lost a packet.
            MyK2HDR.clear();
            Start = false;
        }

    }

    // If Debuggings is on
    if(Debug){
        file.close();
        file2.close();
        Cur++;
    }

}

// Note: The following functions were supposed to be a separate Station Info Handler Class
void K2Status::addK2Status (int index, STATUS_INFO* info){
    // Set Serial Number
    qint32 Serial;
    Serial = qFromBigEndian<quint32>(info->serialNumber);
    Table->setItem(index,Tser,new QStandardItem(QString::number(Serial)));

    // Set Time
    time_t Time;
    Time = (time_t)(qFromBigEndian<quint32>(info->systemTime) + K2_TIME_CONV);
    TimeIDX[index] = Time;

    Table->setItem(index,Ttim,new QStandardItem(QString(asctime(gmtime(&Time)))));

    // Set Clock Source
    switch (info->clockSource) {
    case 0:
        Table->setItem(index,Ttsc,new QStandardItem(QString("Set from RTC\n")));
        Table->item(index,Ttsc)->setBackground(QBrush(Qt::red));
        break;
    case 1:
        Table->setItem(index,Ttsc,new QStandardItem(QString("Set from Keyboard\n")));
        Table->item(index,Ttsc)->setBackground(QBrush(Qt::red));
        break;
    case 2:
        Table->setItem(index,Ttsc,new QStandardItem(QString("Set from External Pulse\n")));
        Table->item(index,Ttsc)->setBackground(QBrush(Qt::yellow));
        break;
    case 3:
        Table->setItem(index,Ttsc,new QStandardItem(QString("Set from Internal GPS\n")));
        Table->item(index,Ttsc)->setBackground(QBrush(Qt::green));
        break;
    default:
        Table->setItem(index,Ttsc,new QStandardItem(QString("Set from (?)\n")));
        Table->item(index,Ttsc)->setBackground(QBrush(Qt::red));
        break;
    }

    // Set HW and Battery Status
    // K2 says battery voltage is zero when it is charging
    int tempbat;
    tempbat = (int) info->batteryStatus;
    if (tempbat > 0)
    {
        if(info->driveStatus){
            Table->setItem(index,Thws,new QStandardItem(QString("OK ")));
            Table->item(index,Thws)->setBackground(QBrush(Qt::green));
        }
        else{
            Table->setItem(index,Thws,new QStandardItem(QString("FAULT")));
            Table->item(index,Thws)->setBackground(QBrush(Qt::red));
        }
        Table->setItem(index,Tbts,new QStandardItem(QString("Not Charging")));
        Table->item(index,Tbts)->setBackground(QBrush(Qt::red));
    }
    else {
        if(info->driveStatus){
            Table->setItem(index,Thws,new QStandardItem(QString("OK")));
            Table->item(index,Thws)->setBackground(QBrush(Qt::green));
        }
        else{
            Table->setItem(index,Thws,new QStandardItem(QString("FAULT")));
            Table->item(index,Thws)->setBackground(QBrush(Qt::red));
        }
        Table->setItem(index,Tbts,new QStandardItem(QString("Charging")));
        Table->item(index,Tbts)->setBackground(QBrush(Qt::green));
    }

    // Drive Status
    unsigned short wtemp1, wtemp2;
    double diskfree;
    char tempchar=0;
    int inde;
    QString Temp;

    for (inde = 0; inde < 2; inde++) {
        wtemp1 = qFromBigEndian<quint16>(info->driveStatus[inde]);
        if (wtemp1 & SF_NOT_READY) {
            if(inde==0){
                Table->setItem(index,Tds1,new QStandardItem(QString("not ready")));
                Table->item(index,Tds1)->setBackground(QBrush(Qt::red));
            }
            else{
                Table->setItem(index,Tds2,new QStandardItem(QString("not ready")));
                Table->item(index,Tds2)->setBackground(QBrush(Qt::red));
            }
        }
        else{
            if ((wtemp1 & SF_GB) == SF_GB){
                tempchar = 'G';
                diskfree = 1073741824.0;   /* `giga' bytes */
            }
            else{
                if ((wtemp1 & SF_MB) == SF_MB) {
                    tempchar = 'M';
                    diskfree = 1048576.0;  /* `mega' bytes */
                }
                else {
                    if ((wtemp1 & SF_KB) == SF_KB) {
                        tempchar = 'K';
                        diskfree = 1024.0;  /* `Kilo' bytes */
                    }
                }
            }
            wtemp2 = wtemp1 & SF_FREE;
            diskfree *= (double)wtemp2;
            if(inde==0){
                Table->setItem(index,Tds1,new QStandardItem(QString::number(wtemp2)+
                                                            QString(" ")+
                                                            QString(tempchar)));
                if ((tempchar == 'M' && wtemp2 < 10) || tempchar == 'K')
                    Table->item(index,Tds1)->setBackground(QBrush(Qt::red));
                else
                    Table->item(index,Tds1)->setBackground(QBrush(Qt::green));
            }
            else{
                Table->setItem(index,Tds2,new QStandardItem(QString::number(wtemp2)+
                                                            QString(" ")+
                                                            QString(tempchar)));
                if ((tempchar == 'M' && wtemp2 < 10) || tempchar == 'K')
                    Table->item(index,Tds2)->setBackground(QBrush(Qt::red));
                else
                    Table->item(index,Tds2)->setBackground(QBrush(Qt::green));
            }
        }
    }

    // Events Registered
    Table->setItem(index,Tevt,new QStandardItem(QString::number(qFromBigEndian<quint16>(info->events))));

    ui->tableView->resizeColumnsToContents();

}

void K2Status::addK2Status2(int index, EXT2_STATUS_INFO* info){
    // Retrive Fault Codes
    quint16 fault;
    fault = qFromBigEndian<quint16>(info->fault);
    if (fault != 0) {
        if (fault & FAULT_SYSTEM){
            Table->setItem(index,Tfac,new QStandardItem(QString("bad parameters")));
            Table->item(index,Tfac)->setBackground(QBrush(Qt::red));
        }
        if (fault & FAULT_FLASH){
            Table->setItem(index,Tfac,new QStandardItem(QString("flash error")));
            Table->item(index,Tfac)->setBackground(QBrush(Qt::red));
        }
        if (fault & FAULT_RAM){
            Table->setItem(index,Tfac,new QStandardItem(QString("ram error at ")+
                                                      QString::number(qFromBigEndian<quint32>(info->lastRAMError))));
            Table->item(index,Tfac)->setBackground(QBrush(Qt::red));
        }
        if (fault & FAULT_PCMCIA){
            Table->setItem(index,Tfac,new QStandardItem(QString("bad/missing PCMCIA")));
            Table->item(index,Tfac)->setBackground(QBrush(Qt::red));
        }
        if (fault & FAULT_DSP){
            Table->setItem(index,Tfac,new QStandardItem(QString("failed to load DSP")));
            Table->item(index,Tfac)->setBackground(QBrush(Qt::red));
        }
        if (fault & FAULT_PARMBLK){
            Table->setItem(index,Tfac,new QStandardItem(QString("param block CRC error")));
            Table->item(index,Tfac)->setBackground(QBrush(Qt::red));
        }
        if (fault & FAULT_FLASH_MAINTENANCE){
            Table->setItem(index,Tfac,new QStandardItem(QString("flash maintenance required")));
            Table->item(index,Tfac)->setBackground(QBrush(Qt::red));
        }
    }
    else{
        Table->setItem(index,Tfac,new QStandardItem(QString("OK")));
        Table->item(index,Tfac)->setBackground(QBrush(Qt::green));
    }

    ui->tableView->resizeColumnsToContents();
}

void K2Status::addK2HeaderS(int index, K2_HEADER*  info){

    // Set Log File
    QFile log;
    QTextStream out;
    out.setDevice(&log);

    // Set Log File Name
    QString logn;
    logn = "logs/"+StationL[index]+"_log.csv";
    log.setFileName(logn);
    log.open(QIODevice::Append);

    // Set Log Time
    time_t now;
    now = time(0);
    double time_now, time_exel;
    time_now = now;
    time_exel = (time_now/86400.0)+25569.0;

    out << now << ", ";
    out << QString::number(time_exel,'f',10) << ", ";

    // Temperature (can also be aquired from EXT2)
    qint16 temp;
    double tempd;
    temp = qFromBigEndian<quint16>(info->roParms.misc.temperature);
    tempd = temp/10.0;
    Table->setItem(index,Ttem,new QStandardItem(QString::number(tempd)));
    if(tempd > 45)
        Table->item(index,Ttem)->setBackground(QBrush(Qt::red));
    else
        Table->item(index,Ttem)->setBackground(QBrush(Qt::green));
    out << tempd << ", ";

    // Battery Voltage (might be aquired from STATUS)
    qint16 batt_voltx10;
    double batv;

    batt_voltx10 = qFromBigEndian<quint16>(info->roParms.misc.batteryVoltage);

    if (batt_voltx10 < 0) {
        batt_voltx10 = -batt_voltx10;
        batv = batt_voltx10 / 10.0;
        Table->setItem(index,Tvol,new QStandardItem(QString::number(batv)));
        if (batv < 12 || batv >= 14)
            Table->item(index,Tvol)->setBackground(QBrush(Qt::red));
        else
            Table->item(index,Tvol)->setBackground(QBrush(Qt::green));
        out << batv << ",  C \n";

        // Add to Archive
        Archive[index].addstninfo(tempd,batv);
        emit update_gview(Archive);
    }
    else {
        batv = batt_voltx10 / 10.0;
        Table->setItem(index,Tvol,new QStandardItem(QString::number(batv)));
        if (batv < 12 || batv >= 14)
            Table->item(index,Tvol)->setBackground(QBrush(Qt::red));
        else
            Table->item(index,Tvol)->setBackground(QBrush(Qt::green));
        out << batv << ", NC \n";

        // Add to Archive (no longer needed reads from file).
        // Archive[index].addstninfo(tempd,batv);
        // emit update_gview(Archive);
    }

    log.close();
}

int K2Status::fetch_index(K2INFO_HEADER* Head){
    int index;
    index = StationL.indexOf(QString(Head->sta));

    // This is a new station
    if (index == -1){
        QList<QStandardItem*> NewRow;
        StationL.append(QString(Head->sta));
        index = StationL.indexOf(QString(Head->sta));
        ui->textBrowser->append(QString("New Station: ")+
                                QString(Head->sta)+
                                QString(" at row ")+
                                QString::number(index));

        NewRow.insert(Tnet,new QStandardItem(QString(Head->net)));
        NewRow.insert(Tsta,new QStandardItem(QString(Head->sta)));
        NewRow.insert(Tser,new QStandardItem(QString("Waiting")));
        NewRow.insert(Tvol,new QStandardItem(QString("Waiting")));
        NewRow.insert(Ttem,new QStandardItem(QString("Waiting")));
        NewRow.insert(Thws,new QStandardItem(QString("Waiting")));
        NewRow.insert(Tbts,new QStandardItem(QString("Waiting")));
        NewRow.insert(Tfac,new QStandardItem(QString("Waiting")));
        NewRow.insert(Ttim,new QStandardItem(QString("Waiting")));
        NewRow.insert(Ttsc,new QStandardItem(QString("Waiting")));
        NewRow.insert(Tds1,new QStandardItem(QString("Waiting")));
        NewRow.insert(Tds2,new QStandardItem(QString("Waiting")));
        NewRow.insert(Tevt,new QStandardItem(QString("Waiting")));
        Table->insertRow(index,NewRow);

        // Set Time
        time_t Time;
        Time = (time_t)(Head->epoch_sent);
        QString all;
        all.append("Last Updated: ");
        all.append(Head->sta);
        all.append(" at ");
        all.append(asctime(gmtime(&Time)));

        // Update Status bar
        ui->statusBar->showMessage(all);

        // Add to archive
        stninfo tmp;
        tmp.setup(QString(Head->sta));
        Archive.append(tmp);
        emit update_gview(Archive);

        // Add to TimeIDX
        time_t now;
        now = time(0);
        TimeIDX.append(now);

        // Return Index
        return index;
    }

    // This is an old station;
    // Set Time
    time_t Time;
    Time = (time_t)(Head->epoch_sent);
    QString all;
    all.append("Last Updated: ");
    all.append(Head->sta);
    all.append(" at ");
    all.append(asctime(gmtime(&Time)));

    // Update Status bar
    ui->statusBar->showMessage(all);

    // Return Index
    return index;
}

// Has recived TCP Msg
void K2Status::has_read_tcp(QByteArray Message){
    if(Debug){

        FileN = QString("File-");
        QString FNum =QString::number(Cur);
        FileN.push_back(FNum);
        FileN.push_back(".txt");

        file.setFileName(FileN);

        out.setDevice(&file);

        file.resize(0);

        file.open(QIODevice::Append);
    }

    ui->textBrowser->append("Message Received: ");
    K2INFO_HEADER *K2IHEAD;
    K2IHEAD = new K2INFO_HEADER;
    int index;

    switch(Message.size()){
    case 80:
        if(Debug)
            ui->textBrowser->append("K2 Extended Status");
        EXT2_STATUS_INFO * EStatus2;
        EStatus2 = new EXT2_STATUS_INFO;
        memcpy(K2IHEAD,Message.data(),sizeof(K2INFO_HEADER));
        memcpy(EStatus2,Message.mid(sizeof(K2INFO_HEADER)).data(),sizeof(EXT2_STATUS_INFO));
        index=fetch_index(K2IHEAD);
        addK2Status2(index,EStatus2);
        delete EStatus2;
        break;

    case 2088:
        if(Debug)
            ui->textBrowser->append("K2 Header Packet");
        K2_HEADER * K2HEAD;
        K2HEAD = new K2_HEADER;
        memcpy(K2IHEAD,Message.data(),sizeof(K2INFO_HEADER));
        memcpy(K2HEAD,Message.mid(sizeof(K2INFO_HEADER)).data(),sizeof(K2_HEADER));
        index=fetch_index(K2IHEAD);
        addK2HeaderS(index,K2HEAD);
        delete K2HEAD;
        break;

    case 60:
        if(Debug)
            ui->textBrowser->append("K2 Status Packet");
        STATUS_INFO * EStatus;
        EStatus = new STATUS_INFO;
        memcpy(K2IHEAD,Message.data(),sizeof(K2INFO_HEADER));
        memcpy(EStatus,Message.mid(sizeof(K2INFO_HEADER)).data(),sizeof(STATUS_INFO));
        index=fetch_index(K2IHEAD);
        addK2Status(index,EStatus);
        delete EStatus;
        break;

    case 104:
        // K2 Communications Package Not read
        break;

    default:
        if(Debug)
            ui->textBrowser->append(FileN+
                                    QString(" Size: ")+
                                    QString::number(Message.size()));
        ui->textBrowser->append("Unknown Packet");
        break;

    }
    delete K2IHEAD;

    if(Debug){
        out << Message;
        Cur++;
        file.close();
    }

}

void K2Status::killTCP() {  
    MessThr->quit();
    delete MessRcv;
    delete MessThr;

    tcpSocket->disconnectFromHost();

    MessThr = new QThread;
    MessRcv = new MessageRcv;

    connect(this,SIGNAL(start_listen(QTcpSocket*,Config*,bool)),
            MessRcv,SLOT(ListenMessage(QTcpSocket*,Config*,bool)));
    connect(MessRcv,SIGNAL(updatetxtbox(QString)),
            this,SLOT(tcpmsgtobox(QString)));
    connect(MessRcv,SIGNAL(ReturnMessage(QByteArray)),
            this,SLOT(has_read_tcp(QByteArray)));

    ui->textBrowser->append("TCP Restarted");
    QHostAddress IPadr(ConfTest.getSendIPQ());
    tcpSocket = new QTcpSocket(this);
    tcpSocket->connectToHost(IPadr,ConfTest.getSendPortI());
}

void K2Status::tcpmsgtobox(QString upd) {
    ui->textBrowser->append(upd);
}

void K2Status::UpdateTimeColors(){
    for (int i=0; i < TimeIDX.size(); i++){
        time_t now, diff;
        now = time(0);
        //stlctm = (TimeIDX[i] + (time_t)60*60*ConfTest.getTZ());
        diff = difftime(now,TimeIDX[i]);

        if (diff < 299){            // Less than 5 min
            Table->item(i,Ttim)->setBackground(QBrush(Qt::green));
        }
        else if (diff >= 300 && diff < 1799){ // Between 5 min and 30 min
            Table->item(i,Ttim)->setBackground(QBrush(Qt::darkGreen));
        }
        else if (diff >= 1800 && diff < 21599){ // Between 30 min and 6 hr
            Table->item(i,Ttim)->setBackground(QBrush(Qt::yellow));
        }
        else if (diff >= 21600 && diff < 43199){ // Between 6 hr and 12 hr
            Table->item(i,Ttim)->setBackground(QBrush(Qt::darkYellow));
        }
        else if (diff >= 43200 && diff < 86399){ // Between 12 hr and 24 hr
            Table->item(i,Ttim)->setBackground(QBrush(Qt::red));
        }
        else {
            Table->item(i,Ttim)->setBackground(QBrush(Qt::darkRed));
        }
    }
}

void K2Status::on_action_Graph_triggered()
{
    GV.show();
}

void K2Status::on_actionAbout_triggered()
{
    Help.show();
}

