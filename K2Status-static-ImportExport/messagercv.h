#ifndef MESSAGERCV_H
#define MESSAGERCV_H
#define INBUFFERSIZE   100

/* Define States for Socket Message Interpretation
 *************************************************/
#define SEARCHING_FOR_MESSAGE_START   0
#define EXPECTING_MESSAGE_START       1
#define ASSEMBLING_MESSAGE            2

/* The sacred characters for framing messages
 ********************************************/
#define STX  2    /* Start Transmission: used to frame beginning of message  */
#define ETX  3    /* End Transmission:   used to frame end of message        */
#define ESC 27    /* Escape: used to 'cloak' unfortunate binary bit patterns */
                  /*         which look like sacred characters               */

#include <QObject>
#include <QTcpSocket>
#include <QString>
#include <QThread>
#include <QTimer>
#include <config.h>

class MessageRcv : public QObject
{
    Q_OBJECT
private:
    QByteArray MsgBuf;
    QTimer HeartbeatTime;
    QTcpSocket *MySock;
    int InstID;
    QString MyString;
    QThread *Timer;
    bool debugon;

public:
    explicit MessageRcv(QObject *parent = 0);

public slots:
    void ListenMessage(QTcpSocket *sock, Config *, bool Debug);

private slots:
    void sendHeartbeat();

signals:
    void ReturnMessage(QByteArray data);
    void CloseConnection();
    void updatetxtbox(QString);


};

#endif // MESSAGERCV_H
