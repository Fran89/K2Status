/********************************************************************************
** Form generated from reading UI file 'defineandconnect.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
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
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DefineAndConnect
{
public:
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_3;
    QLabel *label_9;
    QFormLayout *formLayout;
    QSpacerItem *verticalSpacer;
    QLabel *label;
    QLineEdit *ServerIP;
    QLabel *label_2;
    QLineEdit *ServerPort;
    QLabel *label_3;
    QLineEdit *SendHB;
    QLabel *label_4;
    QLineEdit *SendSTR;
    QLabel *label_5;
    QLineEdit *MyHB;
    QLabel *label_6;
    QLineEdit *MySTR;
    QLabel *label_7;
    QLineEdit *K2INFOID;
    QLabel *label_8;
    QLineEdit *INSTITUTIONID;
    QSpacerItem *verticalSpacer_2;
    QCheckBox *checkBox;
    QLabel *label_10;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DefineAndConnect)
    {
        if (DefineAndConnect->objectName().isEmpty())
            DefineAndConnect->setObjectName(QStringLiteral("DefineAndConnect"));
        DefineAndConnect->resize(678, 462);
        verticalLayout = new QVBoxLayout(DefineAndConnect);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        label_9 = new QLabel(DefineAndConnect);
        label_9->setObjectName(QStringLiteral("label_9"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label_9->setFont(font);

        verticalLayout->addWidget(label_9);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(0, QFormLayout::LabelRole, verticalSpacer);

        label = new QLabel(DefineAndConnect);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label);

        ServerIP = new QLineEdit(DefineAndConnect);
        ServerIP->setObjectName(QStringLiteral("ServerIP"));

        formLayout->setWidget(1, QFormLayout::FieldRole, ServerIP);

        label_2 = new QLabel(DefineAndConnect);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_2);

        ServerPort = new QLineEdit(DefineAndConnect);
        ServerPort->setObjectName(QStringLiteral("ServerPort"));

        formLayout->setWidget(2, QFormLayout::FieldRole, ServerPort);

        label_3 = new QLabel(DefineAndConnect);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_3);

        SendHB = new QLineEdit(DefineAndConnect);
        SendHB->setObjectName(QStringLiteral("SendHB"));

        formLayout->setWidget(3, QFormLayout::FieldRole, SendHB);

        label_4 = new QLabel(DefineAndConnect);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_4);

        SendSTR = new QLineEdit(DefineAndConnect);
        SendSTR->setObjectName(QStringLiteral("SendSTR"));

        formLayout->setWidget(4, QFormLayout::FieldRole, SendSTR);

        label_5 = new QLabel(DefineAndConnect);
        label_5->setObjectName(QStringLiteral("label_5"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_5);

        MyHB = new QLineEdit(DefineAndConnect);
        MyHB->setObjectName(QStringLiteral("MyHB"));

        formLayout->setWidget(5, QFormLayout::FieldRole, MyHB);

        label_6 = new QLabel(DefineAndConnect);
        label_6->setObjectName(QStringLiteral("label_6"));

        formLayout->setWidget(6, QFormLayout::LabelRole, label_6);

        MySTR = new QLineEdit(DefineAndConnect);
        MySTR->setObjectName(QStringLiteral("MySTR"));

        formLayout->setWidget(6, QFormLayout::FieldRole, MySTR);

        label_7 = new QLabel(DefineAndConnect);
        label_7->setObjectName(QStringLiteral("label_7"));

        formLayout->setWidget(7, QFormLayout::LabelRole, label_7);

        K2INFOID = new QLineEdit(DefineAndConnect);
        K2INFOID->setObjectName(QStringLiteral("K2INFOID"));

        formLayout->setWidget(7, QFormLayout::FieldRole, K2INFOID);

        label_8 = new QLabel(DefineAndConnect);
        label_8->setObjectName(QStringLiteral("label_8"));

        formLayout->setWidget(8, QFormLayout::LabelRole, label_8);

        INSTITUTIONID = new QLineEdit(DefineAndConnect);
        INSTITUTIONID->setObjectName(QStringLiteral("INSTITUTIONID"));

        formLayout->setWidget(8, QFormLayout::FieldRole, INSTITUTIONID);


        verticalLayout->addLayout(formLayout);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        checkBox = new QCheckBox(DefineAndConnect);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        verticalLayout->addWidget(checkBox);

        label_10 = new QLabel(DefineAndConnect);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setEnabled(true);

        verticalLayout->addWidget(label_10);

        buttonBox = new QDialogButtonBox(DefineAndConnect);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(DefineAndConnect);
        QObject::connect(buttonBox, SIGNAL(accepted()), DefineAndConnect, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DefineAndConnect, SLOT(reject()));

        QMetaObject::connectSlotsByName(DefineAndConnect);
    } // setupUi

    void retranslateUi(QDialog *DefineAndConnect)
    {
        DefineAndConnect->setWindowTitle(QApplication::translate("DefineAndConnect", "Dialog", 0));
        label_9->setText(QApplication::translate("DefineAndConnect", "    Currently I can only connect to ring2coax transmitting TYPE_K2_STATUS_PACKET", 0));
        label->setText(QApplication::translate("DefineAndConnect", "Server IP Address:", 0));
        ServerIP->setText(QApplication::translate("DefineAndConnect", "127.0.0.1", 0));
        label_2->setText(QApplication::translate("DefineAndConnect", "Server Port: ", 0));
        ServerPort->setText(QApplication::translate("DefineAndConnect", "16005", 0));
        label_3->setText(QApplication::translate("DefineAndConnect", "Sender Heartbeat Rate:", 0));
        SendHB->setText(QApplication::translate("DefineAndConnect", "120", 0));
        label_4->setText(QApplication::translate("DefineAndConnect", "Sender Heartbeat String", 0));
        SendSTR->setText(QApplication::translate("DefineAndConnect", "alive", 0));
        label_5->setText(QApplication::translate("DefineAndConnect", "My Heartbeat Rate: ", 0));
        MyHB->setText(QApplication::translate("DefineAndConnect", "30", 0));
        label_6->setText(QApplication::translate("DefineAndConnect", "My Heartbeat String: ", 0));
        MySTR->setText(QApplication::translate("DefineAndConnect", "alive", 0));
        label_7->setText(QApplication::translate("DefineAndConnect", "K2_INFO_PACKET ID", 0));
        K2INFOID->setText(QApplication::translate("DefineAndConnect", "119", 0));
        label_8->setText(QApplication::translate("DefineAndConnect", "INSTITUTION ID", 0));
        INSTITUTIONID->setText(QApplication::translate("DefineAndConnect", "141", 0));
        INSTITUTIONID->setPlaceholderText(QString());
        checkBox->setText(QApplication::translate("DefineAndConnect", "Click Here for Import/Export", 0));
        label_10->setText(QApplication::translate("DefineAndConnect", "(Full Import/Export Implementation Comming Soon)", 0));
    } // retranslateUi

};

namespace Ui {
    class DefineAndConnect: public Ui_DefineAndConnect {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEFINEANDCONNECT_H
