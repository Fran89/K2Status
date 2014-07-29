/********************************************************************************
** Form generated from reading UI file 'defineandconnect.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEFINEANDCONNECT_H
#define UI_DEFINEANDCONNECT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DefineAndConnect
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLineEdit *ServerIP;
    QLineEdit *ServerPort;
    QLineEdit *SendHB;
    QLineEdit *SendSTR;
    QLineEdit *MyHB;
    QLineEdit *MySTR;
    QLineEdit *K2INFOID;
    QLineEdit *INSTITUTIONID;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_2;
    QLabel *label_9;
    QLabel *label_10;
    QCheckBox *checkBox;

    void setupUi(QDialog *DefineAndConnect)
    {
        if (DefineAndConnect->objectName().isEmpty())
            DefineAndConnect->setObjectName(QStringLiteral("DefineAndConnect"));
        DefineAndConnect->resize(678, 462);
        buttonBox = new QDialogButtonBox(DefineAndConnect);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(320, 420, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        formLayoutWidget = new QWidget(DefineAndConnect);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(60, 70, 571, 291));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(formLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label);

        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_2);

        label_3 = new QLabel(formLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_3);

        label_4 = new QLabel(formLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_4);

        label_5 = new QLabel(formLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_5);

        label_6 = new QLabel(formLayoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        formLayout->setWidget(6, QFormLayout::LabelRole, label_6);

        label_7 = new QLabel(formLayoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));

        formLayout->setWidget(7, QFormLayout::LabelRole, label_7);

        label_8 = new QLabel(formLayoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));

        formLayout->setWidget(8, QFormLayout::LabelRole, label_8);

        ServerIP = new QLineEdit(formLayoutWidget);
        ServerIP->setObjectName(QStringLiteral("ServerIP"));

        formLayout->setWidget(1, QFormLayout::FieldRole, ServerIP);

        ServerPort = new QLineEdit(formLayoutWidget);
        ServerPort->setObjectName(QStringLiteral("ServerPort"));

        formLayout->setWidget(2, QFormLayout::FieldRole, ServerPort);

        SendHB = new QLineEdit(formLayoutWidget);
        SendHB->setObjectName(QStringLiteral("SendHB"));

        formLayout->setWidget(3, QFormLayout::FieldRole, SendHB);

        SendSTR = new QLineEdit(formLayoutWidget);
        SendSTR->setObjectName(QStringLiteral("SendSTR"));

        formLayout->setWidget(4, QFormLayout::FieldRole, SendSTR);

        MyHB = new QLineEdit(formLayoutWidget);
        MyHB->setObjectName(QStringLiteral("MyHB"));

        formLayout->setWidget(5, QFormLayout::FieldRole, MyHB);

        MySTR = new QLineEdit(formLayoutWidget);
        MySTR->setObjectName(QStringLiteral("MySTR"));

        formLayout->setWidget(6, QFormLayout::FieldRole, MySTR);

        K2INFOID = new QLineEdit(formLayoutWidget);
        K2INFOID->setObjectName(QStringLiteral("K2INFOID"));

        formLayout->setWidget(7, QFormLayout::FieldRole, K2INFOID);

        INSTITUTIONID = new QLineEdit(formLayoutWidget);
        INSTITUTIONID->setObjectName(QStringLiteral("INSTITUTIONID"));

        formLayout->setWidget(8, QFormLayout::FieldRole, INSTITUTIONID);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(0, QFormLayout::LabelRole, verticalSpacer);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(9, QFormLayout::LabelRole, verticalSpacer_2);

        label_9 = new QLabel(DefineAndConnect);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(50, 30, 601, 31));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label_9->setFont(font);
        label_10 = new QLabel(DefineAndConnect);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setEnabled(true);
        label_10->setGeometry(QRect(30, 410, 381, 41));
        checkBox = new QCheckBox(DefineAndConnect);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(30, 370, 231, 31));

        retranslateUi(DefineAndConnect);
        QObject::connect(buttonBox, SIGNAL(accepted()), DefineAndConnect, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DefineAndConnect, SLOT(reject()));

        QMetaObject::connectSlotsByName(DefineAndConnect);
    } // setupUi

    void retranslateUi(QDialog *DefineAndConnect)
    {
        DefineAndConnect->setWindowTitle(QApplication::translate("DefineAndConnect", "Dialog", 0));
        label->setText(QApplication::translate("DefineAndConnect", "Server IP Address:", 0));
        label_2->setText(QApplication::translate("DefineAndConnect", "Server Port: ", 0));
        label_3->setText(QApplication::translate("DefineAndConnect", "Sender Heartbeat Rate:", 0));
        label_4->setText(QApplication::translate("DefineAndConnect", "Sender Heartbeat String", 0));
        label_5->setText(QApplication::translate("DefineAndConnect", "My Heartbeat Rate: ", 0));
        label_6->setText(QApplication::translate("DefineAndConnect", "My Heartbeat String: ", 0));
        label_7->setText(QApplication::translate("DefineAndConnect", "K2_INFO_PACKET ID", 0));
        label_8->setText(QApplication::translate("DefineAndConnect", "INSTITUTION ID", 0));
        ServerIP->setText(QApplication::translate("DefineAndConnect", "127.0.0.1", 0));
        ServerPort->setText(QApplication::translate("DefineAndConnect", "16005", 0));
        SendHB->setText(QApplication::translate("DefineAndConnect", "120", 0));
        SendSTR->setText(QApplication::translate("DefineAndConnect", "alive", 0));
        MyHB->setText(QApplication::translate("DefineAndConnect", "30", 0));
        MySTR->setText(QApplication::translate("DefineAndConnect", "alive", 0));
        K2INFOID->setText(QApplication::translate("DefineAndConnect", "119", 0));
        INSTITUTIONID->setText(QApplication::translate("DefineAndConnect", "141", 0));
        INSTITUTIONID->setPlaceholderText(QString());
        label_9->setText(QApplication::translate("DefineAndConnect", "Currently I can only connect to ring2coax transmitting TYPE_K2_STATUS_MESSAGE", 0));
        label_10->setText(QApplication::translate("DefineAndConnect", "(Full Import/Export Implementation Comming Soon)", 0));
        checkBox->setText(QApplication::translate("DefineAndConnect", "Click Here for Import/Export", 0));
    } // retranslateUi

};

namespace Ui {
    class DefineAndConnect: public Ui_DefineAndConnect {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEFINEANDCONNECT_H
