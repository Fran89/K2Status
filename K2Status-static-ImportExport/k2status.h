#ifndef K2STATUS_H
#define K2STATUS_H
#include <QMainWindow>
#include <QUdpSocket>
#include <QTcpSocket>
#include <QFile>
#include <QTableView>
#include <QStandardItemModel>
#include <QList>
#include <QThread>
#include <QTimer>
#include <QTextBrowser>
#include <QtEndian>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "include/ew_packet.h"
#include "include/k2pktdef.h"
#include "include/k2info.h"
#include "include/TableDef.h"
#include "messagercv.h"

#include "config.h"
#include "defineandconnect.h"

class stnnfo{
public:
    QString Stat;
    QVector<time_t> Time;
    QVector<qreal>  Voltage;
    QVector<qreal>  Temperature;
    void addstninfo(qreal Temp, qreal Volt);
    void setup(QString Station);
};


namespace Ui {
class K2Status;
}

class K2Status : public QMainWindow
{
    Q_OBJECT

public:
    explicit K2Status(QWidget *parent = 0);
    ~K2Status();

private:
    // UI and Setup
    Ui::K2Status       *ui;
    DefineAndConnect   *mDefineAndConnect;
    Config             ConfTest;

    //K2 Info Packets
    K2infoPacket       *MyK2Info;
    K2INFO_HEADER      *MyK2Head;    
    QByteArray         MyK2HDR;

    // Communications
    QUdpSocket         *udpSocket;
    QTcpSocket         *tcpSocket;

    // Display
    QStandardItemModel *Table;
    QList<QString>     StationL;

    bool               Start;
    bool               UDPComm;
    bool               Debug;
    int                Cur;

    void parse_UDPpacket(PACKET packet, QByteArray data);

    // Data Handlers
    void addK2Status (int index, STATUS_INFO*     info);
    void addK2Status2(int index, EXT2_STATUS_INFO*info);
    void addK2HeaderS(int index, K2_HEADER*       info);
    int  fetch_index (K2INFO_HEADER*);
    QList<stnnfo> Archive;
    QList<time_t> TimeIDX;

    // Threads
    QThread    *MessThr;
    MessageRcv *MessRcv;
    QThread    *TimeThr;
    QTimer     ColTimer;

    //Debug Var
    QString FileN;
    QString FileN2;
    QFile file;
    QFile file2;
    QTextStream out;
    QTextStream out2;

public slots:

    // UDP Slots
    void Dialog_off   (Config &TestC);
    void has_read_data();

    // TCP Slots
    void has_read_tcp (QByteArray Message);
    void tcpmsgtobox  (QString upd);
    void killTCP      ();

private slots:

    // Internal GUI Slots
    void on_actionAdd_Connection_triggered();
    void on_actionQuit_triggered();
    void on_actionDebug_Mode_triggered();
    void UpdateTimeColors();

signals:

    // TCP Go Signal
    void start_listen(QTcpSocket *, Config*, bool);
};

#endif // K2STATUS_H
