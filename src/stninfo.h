#ifndef STNINFO_H
#define STNINFO_H
#include <QString>
#include <QVector>
#include "time.h"


class stninfo{
public:
    stninfo();
    QVector<qreal> Time;
    QVector<qreal>  Voltage;
    QVector<qreal>  Temperature;
    void addstninfo(qreal Temp, qreal Volt);
    void setup(QString Station);
    bool operator==(const stninfo&);
    QString getName();

private:
    QString Stat;
};

#endif // STNINFO_H
