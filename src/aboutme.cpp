#include "aboutme.h"
#include "ui_aboutme.h"

AboutMe::AboutMe(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutMe)
{
    ui->setupUi(this);
}

AboutMe::~AboutMe()
{
    delete ui;
}

void AboutMe::on_pushButton_clicked()
{
    this->close();
}
