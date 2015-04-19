#include "stninfo.h"

stninfo::stninfo()
{
}

void stninfo::addstninfo(qreal Temp, qreal Volt){
    time_t now;
    now = time(0);
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
        Time.prepend(now);
    }
    else{
        Time.removeLast();
        Time.prepend(now);
    }

}

void stninfo::setup(QString Station){
    Stat = Station;
}
