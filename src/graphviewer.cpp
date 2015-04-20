#include "graphviewer.h"
#include "ui_graphviewer.h"

GraphViewer::GraphViewer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GraphViewer)
{
    ui->setupUi(this);
    this->setWindowTitle("Graph Viewer");
    model = new QStandardItemModel;
}

GraphViewer::~GraphViewer()
{
    delete model;
    delete ui;
}

void GraphViewer::update_archive(QList<stninfo> arc){
    Archive = arc;
    //Populate the spinbox
    ui->Cbox->clear();
    for(int i=0; i < Archive.length(); i++){
        stninfo tmp;
        tmp = Archive.at(i);
        ui->Cbox->addItem(tmp.getName());
    }
}

void GraphViewer::on_do_graph_temp_clicked()
{
    QString STA;
    STA = ui->Cbox->currentText();

    // Set Log File
    QFile file;

    // Set Log File Name
    QString logn;
    logn = "logs/"+STA+"_log.csv";
    file.setFileName(logn);

    stninfo temp;
    bool First = true;
    if (file.open(QIODevice::ReadOnly)) {
        QString data = file.readAll();
        data.remove( QRegExp("\r") ); //remove all ocurrences of CR (Carriage Return)
        QString temp;
        QChar character;
        QTextStream textStream(&data);
        while (!textStream.atEnd()) {
            textStream >> character;
            if (character == ',') {
                checkString(temp, character);
            } else if (character == '\n') {
                checkString(temp, character, First);
                First = false;
            } else if (textStream.atEnd()) {
                temp.append(character);
                checkString(temp);
            } else {
                temp.append(character);
            }
        }
        ui->label->setText(STA);
    } else {
        ui->label->setText("ERROR: NO SUCH FILE");
    }
    temp = modeltostninfo(STA);

    ui->Graph->clearGraphs();
    ui->Graph->addGraph();

    ui->Graph->graph()->setPen(QPen(Qt::blue));
    //ui->Graph->graph()->setBrush(QBrush(QColor(240, 255, 200)));
    ui->Graph->graph()->setData(temp.Time,
                                temp.Temperature);
    ui->Graph->xAxis->rescale();
    ui->Graph->yAxis->rescale();
    QCPRange range;
    range = ui-> Graph->yAxis->range();
    ui->Graph->yAxis->setRangeLower(range.lower-0.5);


    // Set Axis Lable
    ui->Graph->xAxis->setLabel("Date (GMT)");
    ui->Graph->xAxis->setAutoTickStep(false);
    ui->Graph->xAxis->setTickStep(86400);
    ui->Graph->xAxis->setSubTickCount(1);
    ui->Graph->yAxis->setLabel("Temperature (C)");

    //ui->Graph->graph()->addData(time, Archive.at(idx).Voltage);

    // configure bottom axis to show date and time instead of number:
    ui->Graph->xAxis->setTickLabelType(QCPAxis::ltDateTime);
    ui->Graph->xAxis->setDateTimeFormat("d/MM/yyyy");
    ui->Graph->replot();


}

void GraphViewer::on_do_graph_volt_clicked()
{
    QString STA;
    STA = ui->Cbox->currentText();

    // Set Log File
    QFile file;

    // Set Log File Name
    QString logn;
    logn = "logs/"+STA+"_log.csv";
    file.setFileName(logn);

    stninfo temp;
    bool First = true;
    if (file.open(QIODevice::ReadOnly)) {
        QString data = file.readAll();
        data.remove( QRegExp("\r") ); //remove all ocurrences of CR (Carriage Return)
        QString temp;
        QChar character;
        QTextStream textStream(&data);
        while (!textStream.atEnd()) {
            textStream >> character;
            if (character == ',') {
                checkString(temp, character);
            } else if (character == '\n') {
                checkString(temp, character, First);
                First = false;
            } else if (textStream.atEnd()) {
                temp.append(character);
                checkString(temp);
            } else {
                temp.append(character);
            }
        }
        ui->label->setText(STA);
    } else {
        ui->label->setText("ERROR: NO SUCH FILE");
    }
    temp = modeltostninfo(STA);

    ui->Graph->clearGraphs();
    ui->Graph->addGraph();

    ui->Graph->graph()->setPen(QPen(Qt::blue));
    //ui->Graph->graph()->setBrush(QBrush(QColor(240, 255, 200)));
    ui->Graph->graph()->setData(temp.Time,
                                temp.Voltage);
    ui->Graph->xAxis->rescale();
    ui->Graph->yAxis->rescale();
    QCPRange range;
    range = ui-> Graph->yAxis->range();
    ui->Graph->yAxis->setRangeLower(range.lower-0.02);

    // Set Axis Lable
    ui->Graph->xAxis->setLabel("Date (GMT)");
    ui->Graph->xAxis->setAutoTickStep(false);
    ui->Graph->xAxis->setTickStep(86400);
    ui->Graph->xAxis->setSubTickCount(1);
    ui->Graph->yAxis->setLabel("Voltage (Volts)");

    // configure bottom axis to show date and time instead of number:
    ui->Graph->xAxis->setTickLabelType(QCPAxis::ltDateTime);
    ui->Graph->xAxis->setDateTimeFormat("d/MM/yyyy");
    ui->Graph->replot();
}

void GraphViewer::checkString(QString &temp, QChar character, bool First) {
    if(temp.count("\"")%2 == 0) {
        //if (temp.size() == 0 && character != ',') //problem with line endings
        //    return;
        if (temp.startsWith( QChar('\"')) && temp.endsWith( QChar('\"') ) ) {
             temp.remove( QRegExp("^\"") );
             temp.remove( QRegExp("\"$") );
        }
        //FIXME: will possibly fail if there are 4 or more reapeating double quotes
        temp.replace("\"\"", "\"");
        QStandardItem *item = new QStandardItem(temp);
        standardItemList.append(item);
        if (character != QChar(',') && First){
            standardItemList.clear();
        }
        if (character != QChar(',') && !First) {
            model->appendRow(standardItemList);
            standardItemList.clear();
        }
        temp.clear();
    } else {
        temp.append(character);
    }
}

stninfo GraphViewer::modeltostninfo(QString Station){
   stninfo temp;
   temp.setup(Station);
   for (int i=0; i < model->rowCount(); i++){
       double time, temperature, volt;
       for(int j=0; j < model->columnCount(); j++){
           QStandardItem *item;
           switch(j){
           case 0:
               item = model->item(i,j);
               time = item->text().toDouble();
               break;
           case 1:
               break;
           case 2:
               item = model->item(i,j);
               temperature = item->text().toDouble();
               break;
           case 3:
               item = model->item(i,j);
               volt = item->text().toDouble();
               break;
           case 4:
               break;
           default:
               break;
           }
       }
       temp.addstninfo(time,temperature,volt);
   }
   model->clear();
   return temp;
}
