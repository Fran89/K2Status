/********************************************************************************
** Form generated from reading UI file 'k2status.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_K2STATUS_H
#define UI_K2STATUS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_K2Status
{
public:
    QAction *actionAdd_Connection;
    QAction *actionQuit;
    QAction *actionDebug_Mode;
    QAction *action_Graph;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QFormLayout *formLayout_3;
    QLabel *label_2;
    QLabel *ToIP_2;
    QFormLayout *formLayout;
    QLabel *label_3;
    QLabel *ToPort;
    QTableView *tableView;
    QTextBrowser *textBrowser;
    QMenuBar *menuBar;
    QMenu *menuConnection;
    QMenu *menuHelp;
    QStatusBar *statusBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *K2Status)
    {
        if (K2Status->objectName().isEmpty())
            K2Status->setObjectName(QStringLiteral("K2Status"));
        K2Status->resize(760, 467);
        K2Status->setMinimumSize(QSize(760, 467));
        actionAdd_Connection = new QAction(K2Status);
        actionAdd_Connection->setObjectName(QStringLiteral("actionAdd_Connection"));
        actionQuit = new QAction(K2Status);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        actionDebug_Mode = new QAction(K2Status);
        actionDebug_Mode->setObjectName(QStringLiteral("actionDebug_Mode"));
        action_Graph = new QAction(K2Status);
        action_Graph->setObjectName(QStringLiteral("action_Graph"));
        centralWidget = new QWidget(K2Status);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        formLayout_3 = new QFormLayout();
        formLayout_3->setSpacing(6);
        formLayout_3->setObjectName(QStringLiteral("formLayout_3"));
        formLayout_3->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label_2);

        ToIP_2 = new QLabel(centralWidget);
        ToIP_2->setObjectName(QStringLiteral("ToIP_2"));

        formLayout_3->setWidget(0, QFormLayout::FieldRole, ToIP_2);


        horizontalLayout->addLayout(formLayout_3);

        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_3);

        ToPort = new QLabel(centralWidget);
        ToPort->setObjectName(QStringLiteral("ToPort"));

        formLayout->setWidget(0, QFormLayout::FieldRole, ToPort);


        horizontalLayout->addLayout(formLayout);


        verticalLayout->addLayout(horizontalLayout);

        tableView = new QTableView(centralWidget);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

        verticalLayout->addWidget(tableView);

        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setMaximumSize(QSize(16777215, 51));

        verticalLayout->addWidget(textBrowser);

        K2Status->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(K2Status);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 760, 25));
        menuConnection = new QMenu(menuBar);
        menuConnection->setObjectName(QStringLiteral("menuConnection"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        K2Status->setMenuBar(menuBar);
        statusBar = new QStatusBar(K2Status);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        K2Status->setStatusBar(statusBar);
        toolBar = new QToolBar(K2Status);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        toolBar->setMovable(false);
        K2Status->addToolBar(Qt::TopToolBarArea, toolBar);

        menuBar->addAction(menuConnection->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuConnection->addSeparator();
        menuConnection->addAction(actionAdd_Connection);
        menuConnection->addAction(action_Graph);
        menuConnection->addSeparator();
        menuConnection->addAction(actionQuit);
        menuHelp->addAction(actionDebug_Mode);

        retranslateUi(K2Status);

        QMetaObject::connectSlotsByName(K2Status);
    } // setupUi

    void retranslateUi(QMainWindow *K2Status)
    {
        K2Status->setWindowTitle(QApplication::translate("K2Status", "K2Status", 0));
        actionAdd_Connection->setText(QApplication::translate("K2Status", "Add a Connection", 0));
        actionQuit->setText(QApplication::translate("K2Status", "Quit", 0));
        actionDebug_Mode->setText(QApplication::translate("K2Status", "Debug Mode", 0));
        action_Graph->setText(QApplication::translate("K2Status", " Graph", 0));
        label_2->setText(QApplication::translate("K2Status", "Server IP: ", 0));
        ToIP_2->setText(QApplication::translate("K2Status", " UnSet", 0));
        label_3->setText(QApplication::translate("K2Status", "Server Port: ", 0));
        ToPort->setText(QApplication::translate("K2Status", "UnSet", 0));
        menuConnection->setTitle(QApplication::translate("K2Status", "Connection", 0));
        menuHelp->setTitle(QApplication::translate("K2Status", "Help", 0));
        toolBar->setWindowTitle(QApplication::translate("K2Status", "toolBar", 0));
    } // retranslateUi

};

namespace Ui {
    class K2Status: public Ui_K2Status {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_K2STATUS_H
