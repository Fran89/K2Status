#include "stninfo.h"

stninfo::stninfo()
{
}

void stninfo::addstninfo(qreal Temp, qreal Volt){
    time_t now = time(0);
    double timed = now;
    if(Temperature.size() < 500){
        Temperature.prepend(Temp);
    }
    else{
        Temperature.removeLast();
        Temperature.prepend(Temp);
    }
    if(Voltage.size() < 500){
        Voltage.prepend(Volt);
    }
    else{
        Voltage.removeLast();
        Voltage.prepend(Volt);
    }
    if(Time.size() < 500){
        Time.prepend(timed);
    }
    else{
        Time.removeLast();
        Time.prepend(timed);
    }

}

void stninfo::setup(QString Station){
    Stat = Station;
}

QString stninfo::getName(){
    return Stat;
}

bool stninfo::operator ==(const stninfo &b){
    if(this->Stat == b.Stat)
        return true;
    else
        return false;
}
