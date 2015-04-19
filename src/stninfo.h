#ifndef STNINFO_H
#define STNINFO_H
#include <QString>
#include <QVector>


class stninfo{
public:
    stninfo();
    QString Stat;
    QVector<time_t> Time;
    QVector<qreal>  Voltage;
    QVector<qreal>  Temperature;
    void addstninfo(qreal Temp, qreal Volt);
    void setup(QString Station);
    bool operator==(const stninfo&);
};

#endif // STNINFO_H
