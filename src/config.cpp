#include "config.h"
#include <QApplication>

Config::Config(){
    verbose=0;
    HeartbeatDebug=0;
}

Config::~Config()
{
}

char *Config::QstringtoChar(QString msg){
    QByteArray byteArray = msg.toUtf8();
    const char* cString = byteArray.constData();
    char * p2;
    p2 = const_cast<char *>(cString);
    return p2;
}

void Config::setK2INFOID(QString MMS){
    MaxMsgSize = MMS.toInt();
}

void Config::setMyHR(QString MAI){
    MyAliveInt = MAI.toInt();
}

void Config::setMyHS(QString MAS){
    MyAliveString = QstringtoChar(MAS);
    MyAliveStringQT = MAS;
}

void Config::setSendIP(QString IP){
    SenderIpAdr = QstringtoChar(IP);
    SenderIpAdrQT = IP;
}

void Config::setSendPort(QString port){
    SenderPort = QstringtoChar(port);
    PortAdr = port.toInt();
    SenderPortQT = port;

}

void Config::setSendHR(QString EHB){
    SenderHeartRate = EHB.toInt();
}

void Config::setSendHS(QString EHS){
    SenderHeartText = QstringtoChar(EHS);
    SenderHeartTextQT = EHS;
}

void Config::setINSTID(QString STL){
    SocketTimeoutLength = STL.toInt();
}

void Config::setTZ(QString TimeZ){
    TZ= TimeZ.toInt();
}

int Config::getK2INFOID(){
    return MaxMsgSize;
}

int Config::getMyHR(){
    return MyAliveInt;
}

int Config::getSendHR(){
    return SenderHeartRate;
}

int Config::getHeartbeatDebug(){
    return HeartbeatDebug;
}

int Config::getINSTID(){
    return SocketTimeoutLength;
}

int Config::getVerbose(){
    return verbose;
}

char *Config::getMyHS(){
    return MyAliveString;
}

QString Config::getMyHSQ(){
    return MyAliveStringQT;
}

char *Config::getSendHS(){
    return SenderHeartText;
}

QString Config::getSendHSQ(){
    return SenderHeartTextQT;
}

char *Config::getSendIP(){
    return SenderIpAdr;
}

QString Config::getSendIPQ(){
    return SenderIpAdrQT;
}

char *Config::getSendPort(){
    return SenderPort;
}

QString Config::getSendPortQ(){
    return SenderPortQT;
}

quint16 Config::getSendPortI(){
    return PortAdr;
}

int Config::getTZ(){
    return TZ;
}
