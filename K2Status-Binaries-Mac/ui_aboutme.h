/********************************************************************************
** Form generated from reading UI file 'aboutme.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTME_H
#define UI_ABOUTME_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AboutMe
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTextBrowser *textBrowser;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;

    void setupUi(QDialog *AboutMe)
    {
        if (AboutMe->objectName().isEmpty())
            AboutMe->setObjectName(QStringLiteral("AboutMe"));
        AboutMe->resize(568, 409);
        verticalLayout = new QVBoxLayout(AboutMe);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(AboutMe);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(18);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        textBrowser = new QTextBrowser(AboutMe);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));

        verticalLayout->addWidget(textBrowser);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton = new QPushButton(AboutMe);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(AboutMe);

        QMetaObject::connectSlotsByName(AboutMe);
    } // setupUi

    void retranslateUi(QDialog *AboutMe)
    {
        AboutMe->setWindowTitle(QApplication::translate("AboutMe", "Dialog", 0));
        label->setText(QApplication::translate("AboutMe", "K2Status", 0));
        textBrowser->setHtml(QApplication::translate("AboutMe", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:16px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:1.2%;\"><span style=\" font-family:'Helvetica Neue,Helvetica,Segoe UI,Arial,freesans,sans-serif'; font-size:xx-large; font-weight:600; color:#333333;\">K2Status</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:16px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:1.2%; font-family:'Helvetica Neue,Helvetica,Segoe UI,Arial,freesans,sans-serif'; font-size:xx-large; font-weight:600; color:#333333;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:16px; mar"
                        "gin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:1.2%; font-family:'Helvetica Neue,Helvetica,Segoe UI,Arial,freesans,sans-serif'; font-size:xx-large; font-weight:600; color:#333333;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:16px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:25.6px;\"><span style=\" font-family:'Helvetica Neue,Helvetica,Segoe UI,Arial,freesans,sans-serif'; font-size:16px; color:#333333;\">A K2/ETNA Status Monitoring Program for Earthworm</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:16px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:25.6px;\"><span style=\" font-family:'Helvetica Neue,Helvetica,Segoe UI,Arial,freesans,sans-serif'; font-size:16px; color:#333333;\">This K2 Status program is compiled for 64bit Intel, but can be compiled easily in any 32bit computer. It has been written in QT and C++ in order to have full compatibility for other platforms. The 32"
                        "Bit statically link version availible in the master branch for a previous version (I will update soon). A fully naitive 64bit (dinamically linked) version is provided and run in the newest Ubuntu distros.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><a name=\"user-content-features\"></a><span style=\" font-family:'Helvetica Neue,Helvetica,Segoe UI,Arial,freesans,sans-serif'; font-size:medium; font-weight:600; color:#333333;\">F</span><span style=\" font-family:'Helvetica Neue,Helvetica,Segoe UI,Arial,freesans,sans-serif'; font-size:medium; font-weight:600; color:#333333;\">eatures:</span></p>\n"
"<ul style=\"margin-top: 0px; margin-bottom: 0px; margin-left: 0px; margin-right: 0px; -qt-list-indent: 1;\"><li style=\" font-family:'Helvetica Neue,Helvetica,Segoe UI,Arial,freesans,sans-serif'; font-size:16px; color:#333333;\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; te"
                        "xt-indent:0px;\"><span style=\" font-size:16px;\">Shows updated status for every station (it automatically configures stations)</span></li>\n"
"<li style=\" font-family:'Helvetica Neue,Helvetica,Segoe UI,Arial,freesans,sans-serif'; font-size:16px; color:#333333;\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16px;\">Shows you a lot of statistics from stations provided directly from the station.</span></li>\n"
"<li style=\" font-family:'Helvetica Neue,Helvetica,Segoe UI,Arial,freesans,sans-serif'; font-size:16px; color:#333333;\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16px;\">Colors that indicate the different status, gives you 'at a glance' overview of the network</span></li>\n"
"<li style=\" font-family:'Helvetica Neue,Helvetica,Segoe UI,Arial,freesans,sans-serif'; font-size:16px; color:#333333;\" style=\" marg"
                        "in-top:0px; margin-bottom:16px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16px;\">Potential for a lot of features to be added (see below)</span></li></ul>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><a name=\"user-content-color-coding\"></a><span style=\" font-family:'Helvetica Neue,Helvetica,Segoe UI,Arial,freesans,sans-serif'; font-size:medium; font-weight:600; color:#333333;\">C</span><span style=\" font-family:'Helvetica Neue,Helvetica,Segoe UI,Arial,freesans,sans-serif'; font-size:medium; font-weight:600; color:#333333;\">olor Coding</span></p>\n"
"<ol style=\"margin-top: 0px; margin-bottom: 0px; margin-left: 0px; margin-right: 0px; -qt-list-indent: 1;\"><li style=\" font-family:'Helvetica Neue,Helvetica,Segoe UI,Arial,freesans,sans-serif'; font-size:16px; color:#333333;\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0;"
                        " text-indent:0px;\"><span style=\" font-size:16px;\">Update Time:</span></li>\n"
"<ul style=\"margin-top: 0px; margin-bottom: 0px; margin-left: 0px; margin-right: 0px; -qt-list-indent: 2;\"><li style=\" font-family:'Helvetica Neue,Helvetica,Segoe UI,Arial,freesans,sans-serif'; font-size:16px; color:#333333;\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16px;\">Green: Less than 5min.</span></li>\n"
"<li style=\" font-family:'Helvetica Neue,Helvetica,Segoe UI,Arial,freesans,sans-serif'; font-size:16px; color:#333333;\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16px;\">Dark Green: 5min and 30min</span></li>\n"
"<li style=\" font-family:'Helvetica Neue,Helvetica,Segoe UI,Arial,freesans,sans-serif'; font-size:16px; color:#333333;\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block"
                        "-indent:0; text-indent:0px;\"><span style=\" font-size:16px;\">Yellow: 30min and 6 hr</span></li>\n"
"<li style=\" font-family:'Helvetica Neue,Helvetica,Segoe UI,Arial,freesans,sans-serif'; font-size:16px; color:#333333;\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16px;\">Dark Yellow: 6hr and 12 hr</span></li>\n"
"<li style=\" font-family:'Helvetica Neue,Helvetica,Segoe UI,Arial,freesans,sans-serif'; font-size:16px; color:#333333;\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16px;\">Red: 12hr and 24hr</span></li>\n"
"<li style=\" font-family:'Helvetica Neue,Helvetica,Segoe UI,Arial,freesans,sans-serif'; font-size:16px; color:#333333;\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16px;\">Dark Red: More than 24 hrs</s"
                        "pan></li></ul>\n"
"<li style=\" font-family:'Helvetica Neue,Helvetica,Segoe UI,Arial,freesans,sans-serif'; font-size:16px; color:#333333;\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16px;\">Time Src:</span></li>\n"
"<ul style=\"margin-top: 0px; margin-bottom: 0px; margin-left: 0px; margin-right: 0px; -qt-list-indent: 2;\"><li style=\" font-family:'Helvetica Neue,Helvetica,Segoe UI,Arial,freesans,sans-serif'; font-size:16px; color:#333333;\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16px;\">Green only on GPS</span></li>\n"
"<li style=\" font-family:'Helvetica Neue,Helvetica,Segoe UI,Arial,freesans,sans-serif'; font-size:16px; color:#333333;\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16px;\">Red on RTC, Keyboard a"
                        "nd (?)</span></li>\n"
"<li style=\" font-family:'Helvetica Neue,Helvetica,Segoe UI,Arial,freesans,sans-serif'; font-size:16px; color:#333333;\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16px;\">Yellow on External Pulse</span></li></ul>\n"
"<li style=\" font-family:'Helvetica Neue,Helvetica,Segoe UI,Arial,freesans,sans-serif'; font-size:16px; color:#333333;\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16px;\">Voltage:</span></li>\n"
"<ul style=\"margin-top: 0px; margin-bottom: 0px; margin-left: 0px; margin-right: 0px; -qt-list-indent: 2;\"><li style=\" font-family:'Helvetica Neue,Helvetica,Segoe UI,Arial,freesans,sans-serif'; font-size:16px; color:#333333;\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16px;\">Green b"
                        "etween 12 and 14, red otherwise,</span></li></ul>\n"
"<li style=\" font-family:'Helvetica Neue,Helvetica,Segoe UI,Arial,freesans,sans-serif'; font-size:16px; color:#333333;\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16px;\">Temperature:</span></li>\n"
"<ul style=\"margin-top: 0px; margin-bottom: 0px; margin-left: 0px; margin-right: 0px; -qt-list-indent: 2;\"><li style=\" font-family:'Helvetica Neue,Helvetica,Segoe UI,Arial,freesans,sans-serif'; font-size:16px; color:#333333;\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16px;\">Red on 45C and up</span></li></ul>\n"
"<li style=\" font-family:'Helvetica Neue,Helvetica,Segoe UI,Arial,freesans,sans-serif'; font-size:16px; color:#333333;\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style="
                        "\" font-size:16px;\">Hardware, Battery Status and Fault Code:</span></li>\n"
"<ul style=\"margin-top: 0px; margin-bottom: 0px; margin-left: 0px; margin-right: 0px; -qt-list-indent: 2;\"><li style=\" font-family:'Helvetica Neue,Helvetica,Segoe UI,Arial,freesans,sans-serif'; font-size:16px; color:#333333;\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16px;\">Green if OK or Charging, Red otherwise</span></li></ul>\n"
"<li style=\" font-family:'Helvetica Neue,Helvetica,Segoe UI,Arial,freesans,sans-serif'; font-size:16px; color:#333333;\" style=\" margin-top:0px; margin-bottom:16px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16px;\">Disk Space:</span></li></ol>\n"
"<ul style=\"margin-top: 0px; margin-bottom: 0px; margin-left: 0px; margin-right: 0px; -qt-list-indent: 2;\"><li style=\" font-family:'Helvetica Neue,Helvetica,Segoe UI,Arial,freesans,sans-serif'; font-"
                        "size:16px; color:#333333;\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16px;\">Red if space goes under 10 Mb</span></li></ul>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Helvetica Neue,Helvetica,Segoe UI,Arial,freesans,sans-serif'; font-size:16px; color:#333333;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><a name=\"user-content-instructions\"></a><span style=\" font-family:'Helvetica Neue,Helvetica,Segoe UI,Arial,freesans,sans-serif'; font-size:medium; font-weight:600; color:#333333;\">I</span><span style=\" font-family:'Helvetica Neue,Helvetica,Segoe UI,Arial,freesans,sans-serif'; font-size:medium; font-weight:600; color:#333333;\">nstructions:</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:16p"
                        "x; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:25.6px;\"><span style=\" font-family:'Helvetica Neue,Helvetica,Segoe UI,Arial,freesans,sans-serif'; font-size:16px; color:#333333;\">In EW:</span></p>\n"
"<ol style=\"margin-top: 0px; margin-bottom: 0px; margin-left: 0px; margin-right: 0px; -qt-list-indent: 1;\"><li style=\" font-family:'Helvetica Neue,Helvetica,Segoe UI,Arial,freesans,sans-serif'; font-size:16px; color:#333333;\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16px;\">Add the TYPE_K2INFO_PACKET Message type to earthworm.d</span></li>\n"
"<li style=\" font-family:'Helvetica Neue,Helvetica,Segoe UI,Arial,freesans,sans-serif'; font-size:16px; color:#333333;\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16px;\">Setup all the K2EW instances to transmit K2Info Packets. (Un"
                        "comment the injectInfo line)</span></li>\n"
"<li style=\" font-family:'Helvetica Neue,Helvetica,Segoe UI,Arial,freesans,sans-serif'; font-size:16px; color:#333333;\" style=\" margin-top:0px; margin-bottom:16px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16px;\">Setup a ringtocoax to transmit this particular packet(BroadcasLogo to TYPE_K2INFO_PACKET) to the computer which will run K2Status.</span></li></ol>\n"
"<p style=\" margin-top:0px; margin-bottom:16px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:25.6px;\"><span style=\" font-family:'Helvetica Neue,Helvetica,Segoe UI,Arial,freesans,sans-serif'; font-size:16px; color:#333333;\">In K2Status:</span></p>\n"
"<ol style=\"margin-top: 0px; margin-bottom: 0px; margin-left: 0px; margin-right: 0px; -qt-list-indent: 1;\"><li style=\" font-family:'Helvetica Neue,Helvetica,Segoe UI,Arial,freesans,sans-serif'; font-size:16px; color:#333333;\" style=\" margin-top:0px; margin-b"
                        "ottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16px;\">In the Connections Menu:</span></li>\n"
"<li style=\" font-family:'Helvetica Neue,Helvetica,Segoe UI,Arial,freesans,sans-serif'; font-size:16px; color:#333333;\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16px;\">Put the IP of the interface you are to recieve the UDP packets containing the K2 Info (ususally the ip of the computer).</span></li>\n"
"<li style=\" font-family:'Helvetica Neue,Helvetica,Segoe UI,Arial,freesans,sans-serif'; font-size:16px; color:#333333;\" style=\" margin-top:0px; margin-bottom:16px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16px;\">That's it.</span></li></ol>\n"
"<p style=\" margin-top:0px; margin-bottom:16px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:25.6px;\"><span styl"
                        "e=\" font-family:'Helvetica Neue,Helvetica,Segoe UI,Arial,freesans,sans-serif'; font-size:16px; color:#333333;\">Import/Export Capability: Is fully EXPERIMENTAL, use at your own risk.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><a name=\"user-content-to-do\"></a><span style=\" font-family:'Helvetica Neue,Helvetica,Segoe UI,Arial,freesans,sans-serif'; font-size:medium; font-weight:600; color:#333333;\">T</span><span style=\" font-family:'Helvetica Neue,Helvetica,Segoe UI,Arial,freesans,sans-serif'; font-size:medium; font-weight:600; color:#333333;\">o Do:</span></p>\n"
"<ol style=\"margin-top: 0px; margin-bottom: 0px; margin-left: 0px; margin-right: 0px; -qt-list-indent: 1;\"><li style=\" font-family:'Helvetica Neue,Helvetica,Segoe UI,Arial,freesans,sans-serif'; font-size:16px; color:#333333;\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span styl"
                        "e=\" font-size:16px;\">Work out\302\240various\302\240bugs (Most are squashed).</span></li>\n"
"<li style=\" font-family:'Helvetica Neue,Helvetica,Segoe UI,Arial,freesans,sans-serif'; font-size:16px; color:#333333;\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16px;\">Improve Import/Export Communications.</span></li>\n"
"<li style=\" font-family:'Helvetica Neue,Helvetica,Segoe UI,Arial,freesans,sans-serif'; font-size:16px; color:#333333;\" style=\" margin-top:0px; margin-bottom:16px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16px;\">Add the ability to request information from the Rock Family of instruments.</span></li></ol>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><a name=\"user-content-log-file\"></a><span style=\" font-family:'Helvetica Neue,Helvetica,Segoe UI,Arial,freesa"
                        "ns,sans-serif'; font-size:medium; font-weight:600; color:#333333;\">L</span><span style=\" font-family:'Helvetica Neue,Helvetica,Segoe UI,Arial,freesans,sans-serif'; font-size:medium; font-weight:600; color:#333333;\">og File:</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:16px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:25.6px;\"><span style=\" font-family:'Helvetica Neue,Helvetica,Segoe UI,Arial,freesans,sans-serif'; font-size:16px; color:#333333;\">The log file does not have a header, it's a pure CSV file with the following columns:</span></p>\n"
"<ol style=\"margin-top: 0px; margin-bottom: 0px; margin-left: 0px; margin-right: 0px; -qt-list-indent: 1;\"><li style=\" font-family:'Helvetica Neue,Helvetica,Segoe UI,Arial,freesans,sans-serif'; font-size:16px; color:#333333;\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16px;\">Local unix timestamp at which the rea"
                        "dings were recorded.</span></li>\n"
"<li style=\" font-family:'Helvetica Neue,Helvetica,Segoe UI,Arial,freesans,sans-serif'; font-size:16px; color:#333333;\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16px;\">GMT Timestamp for excel sheet format. (Format to whatever time/date is better for you to visualize in excel)</span></li>\n"
"<li style=\" font-family:'Helvetica Neue,Helvetica,Segoe UI,Arial,freesans,sans-serif'; font-size:16px; color:#333333;\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16px;\">Temperature reading at the station.</span></li>\n"
"<li style=\" font-family:'Helvetica Neue,Helvetica,Segoe UI,Arial,freesans,sans-serif'; font-size:16px; color:#333333;\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16p"
                        "x;\">Voltage at the station.</span></li>\n"
"<li style=\" font-family:'Helvetica Neue,Helvetica,Segoe UI,Arial,freesans,sans-serif'; font-size:16px; color:#333333;\" style=\" margin-top:0px; margin-bottom:16px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16px;\">Charging status ( 'C' for Charging, 'NC' for Not Charging)</span></li></ol>\n"
"<p style=\" margin-top:0px; margin-bottom:16px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:25.6px;\"><span style=\" font-family:'Helvetica Neue,Helvetica,Segoe UI,Arial,freesans,sans-serif'; font-size:16px; color:#333333;\">If anyone is interested in this proyect or would like to help, contact me!</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><a name=\"user-content-credits\"></a><span style=\" font-family:'Helvetica Neue,Helvetica,Segoe UI,Arial,freesans,sans-serif'; font-weight:600; color:#"
                        "777777;\">C</span><span style=\" font-family:'Helvetica Neue,Helvetica,Segoe UI,Arial,freesans,sans-serif'; font-weight:600; color:#777777;\">redits:</span></p>\n"
"<ul style=\"margin-top: 0px; margin-bottom: 0px; margin-left: 0px; margin-right: 0px; -qt-list-indent: 1;\"><li style=\" font-family:'Helvetica Neue,Helvetica,Segoe UI,Arial,freesans,sans-serif'; font-size:16px; color:#333333;\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16px;\">The Puerto Rico Strong Motion Program for their help and support.</span></li>\n"
"<li style=\" font-family:'Helvetica Neue,Helvetica,Segoe UI,Arial,freesans,sans-serif'; font-size:16px; color:#333333;\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16px;\">The people over at Instrumental Software Technologies, Inc. (ISTI) @\302\240</span><a href=\"http://www.isti.com/\"><span styl"
                        "e=\" font-size:16px; text-decoration: underline; color:#4183c4; background-color:transparent;\">http://www.isti.com/</span></a></li>\n"
"<li style=\" font-family:'Helvetica Neue,Helvetica,Segoe UI,Arial,freesans,sans-serif'; font-size:16px; color:#333333;\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16px;\">Everyone who has ever worked with in the development of earthworm @</span><a href=\"http://earthwormcentral.org/\"><span style=\" font-size:16px; text-decoration: underline; color:#4183c4; background-color:transparent;\">http://earthwormcentral.org</span></a></li>\n"
"<li style=\" font-family:'Helvetica Neue,Helvetica,Segoe UI,Arial,freesans,sans-serif'; font-size:16px; color:#333333;\" style=\" margin-top:0px; margin-bottom:16px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16px;\">The QT Community @\302\240</span><a href=\"http://qt-project.org/\"><span "
                        "style=\" font-size:16px; text-decoration: underline; color:#4183c4; background-color:transparent;\">http://qt-project.org/</span></a></li></ul>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:25.6px;\"><span style=\" font-family:'Helvetica Neue,Helvetica,Segoe UI,Arial,freesans,sans-serif'; font-size:16px; color:#333333;\">Thanks, </span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:25.6px;\"><span style=\" font-family:'Helvetica Neue,Helvetica,Segoe UI,Arial,freesans,sans-serif'; font-size:16px; color:#333333;\">Francisco J. Hernandez</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:25.6px; font-family:'Helvetica Neue,Helvetica,Segoe UI,Arial,freesans,sans-serif'; font-size:16px; color:#333333;\"><br /></p>\n"
""
                        "<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", 0));
        pushButton->setText(QApplication::translate("AboutMe", "Ok, thanks!", 0));
    } // retranslateUi

};

namespace Ui {
    class AboutMe: public Ui_AboutMe {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTME_H
