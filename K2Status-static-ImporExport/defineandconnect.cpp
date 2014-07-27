#include "defineandconnect.h"
#include "ui_defineandconnect.h"

DefineAndConnect::DefineAndConnect(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DefineAndConnect)
{
    ui->setupUi(this);
    ui->label_3->hide();
    ui->label_4->hide();
    ui->label_5->hide();
    ui->label_6->hide();
    ui->label_7->hide();
    ui->label_8->hide();
    ui->label_10->hide();
    ui->SendHB->hide();
    ui->SendSTR->hide();
    ui->MyHB->hide();
    ui->MySTR->hide();
    ui->INSTITUTIONID->hide();
    ui->K2INFOID->hide();
    CTest1.Comm = true;
}

DefineAndConnect::~DefineAndConnect()
{
    delete ui;
}

void DefineAndConnect::on_buttonBox_accepted()
{
   CTest1.setINSTID(ui->INSTITUTIONID->text());
   CTest1.setMyHR(ui->MyHB->text());
   CTest1.setMyHS(ui->MySTR->text());
   CTest1.setSendHR(ui->SendHB->text());
   CTest1.setSendHS(ui->SendSTR->text());
   CTest1.setSendIP(ui->ServerIP->text());
   CTest1.setSendPort(ui->ServerPort->text());
   CTest1.setK2INFOID(ui->K2INFOID->text());
   emit this->endingsig(CTest1);
}

void DefineAndConnect::on_checkBox_toggled(bool checked)
{
    if (checked){
        ui->label_3->show();
        ui->label_4->show();
        ui->label_5->show();
        ui->label_6->show();
        ui->label_7->show();
        ui->label_8->show();
        ui->label_10->show();
        ui->SendHB->show();
        ui->SendSTR->show();
        ui->MyHB->show();
        ui->MySTR->show();
        ui->K2INFOID->show();
        ui->INSTITUTIONID->show();
        CTest1.Comm = false;
    }
    else {
        ui->label_3->hide();
        ui->label_4->hide();
        ui->label_5->hide();
        ui->label_6->hide();
        ui->label_7->hide();
        ui->label_8->hide();
        ui->label_10->hide();
        ui->SendHB->hide();
        ui->SendSTR->hide();
        ui->MyHB->hide();
        ui->MySTR->hide();
        ui->K2INFOID->hide();
        ui->INSTITUTIONID->hide();
        CTest1.Comm = true;
    }
}
