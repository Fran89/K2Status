#ifndef CONFIG_H
#define CONFIG_H
#include <QApplication>

class Config
{
    /* Things to read or derive from configuration file */
    int  verbose;
    int  MaxMsgSize;             /* max size for input/output msgs    */
    int  MyAliveInt;             /* Seconds between sending alive     */
                                 /* message to foreign sender         */
    int  SenderHeartRate;        /* Expect alive messages this often from foreign sender */
    int  SocketTimeoutLength;     /* Length of timeouts on SOCKET_ew calls */
    int  HeartbeatDebug;          /* set to 1 in for heartbeat debug mess  */
    char *MyAliveString;         /* Text of above alive message       */
    QString MyAliveStringQT;     /* Text of above alive message OT    */
    char *SenderIpAdr;           /* Sender server address, in dot notation     */
    QString SenderIpAdrQT;       /* Sender server address, in dot notation  QT */
    char *SenderPort;            /* Sender server port number     */
    QString SenderPortQT;        /* Sender server port number  QT */
    char *SenderHeartText;       /* Text making up the sender's heart beat message   */
    QString SenderHeartTextQT;   /* Text making up the sender's heart beat message QT*/
    quint16 PortAdr;
    char* QstringtoChar(QString msg);

public:
    Config();
    ~Config();
    void setK2INFOID(QString MMS);
    void setMyHR(QString MAI);
    void setMyHS(QString Mas);
    void setSendIP(QString IP);
    void setSendPort(QString port);
    void setSendHR(QString EHR);
    void setSendHS(QString EHS);
    void setINSTID(QString STL);
    int getK2INFOID();
    int getMyHR  ();
    int getSendHR();
    int getHeartbeatDebug();
    int getINSTID();
    int getVerbose();
    char* getMyHS();
    QString getMyHSQ();
    char* getSendHS();
    QString getSendHSQ();
    char* getSendIP();
    QString getSendIPQ();
    char* getSendPort();
    QString getSendPortQ();
    quint16 getSendPortI();
    bool Comm;
};

#endif // CONFIG_H
