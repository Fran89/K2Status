#include "k2status.h"
#include <climits>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    K2Status w;
    w.setWindowIcon(QIcon(":icons/Test.png"));
    w.show();

    return a.exec();
}
