/********************************************************************************
** Form generated from reading UI file 'graphviewer.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRAPHVIEWER_H
#define UI_GRAPHVIEWER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_GraphViewer
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *do_graph_temp;
    QPushButton *do_graph_volt;
    QComboBox *Cbox;
    QCustomPlot *Graph;
    QLabel *label;

    void setupUi(QWidget *GraphViewer)
    {
        if (GraphViewer->objectName().isEmpty())
            GraphViewer->setObjectName(QStringLiteral("GraphViewer"));
        GraphViewer->resize(735, 496);
        gridLayout = new QGridLayout(GraphViewer);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        do_graph_temp = new QPushButton(GraphViewer);
        do_graph_temp->setObjectName(QStringLiteral("do_graph_temp"));

        horizontalLayout->addWidget(do_graph_temp);

        do_graph_volt = new QPushButton(GraphViewer);
        do_graph_volt->setObjectName(QStringLiteral("do_graph_volt"));

        horizontalLayout->addWidget(do_graph_volt);

        Cbox = new QComboBox(GraphViewer);
        Cbox->setObjectName(QStringLiteral("Cbox"));

        horizontalLayout->addWidget(Cbox);


        gridLayout->addLayout(horizontalLayout, 2, 0, 1, 1);

        Graph = new QCustomPlot(GraphViewer);
        Graph->setObjectName(QStringLiteral("Graph"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Graph->sizePolicy().hasHeightForWidth());
        Graph->setSizePolicy(sizePolicy);

        gridLayout->addWidget(Graph, 1, 0, 1, 1);

        label = new QLabel(GraphViewer);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);


        retranslateUi(GraphViewer);

        QMetaObject::connectSlotsByName(GraphViewer);
    } // setupUi

    void retranslateUi(QWidget *GraphViewer)
    {
        GraphViewer->setWindowTitle(QApplication::translate("GraphViewer", "Form", 0));
        do_graph_temp->setText(QApplication::translate("GraphViewer", "Graph / Refresh Temperature", 0));
        do_graph_volt->setText(QApplication::translate("GraphViewer", "Graph / Refresh Voltage", 0));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class GraphViewer: public Ui_GraphViewer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAPHVIEWER_H
