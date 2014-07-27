#ifndef DEFINEANDCONNECT_H
#define DEFINEANDCONNECT_H
#include "config.h"
#include <QDialog>

namespace Ui {
class DefineAndConnect;
}

class DefineAndConnect : public QDialog
{
    Q_OBJECT

public:
    explicit DefineAndConnect(QWidget *parent = 0);
    ~DefineAndConnect();
    Config CTest1;
signals:
    void endingsig(Config &TestC);

private slots:
    void on_buttonBox_accepted();
    void on_checkBox_toggled(bool checked);

private:
    Ui::DefineAndConnect *ui;
};

#endif // DEFINEANDCONNECT_H
