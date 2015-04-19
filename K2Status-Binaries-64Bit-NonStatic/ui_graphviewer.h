/********************************************************************************
** Form generated from reading UI file 'graphviewer.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_GraphViewer
{
public:
    QGridLayout *gridLayout;
    QCustomPlot *Graph;
    QHBoxLayout *horizontalLayout;
    QPushButton *do_graph;
    QPushButton *Refresh;
    QComboBox *Cbox;

    void setupUi(QWidget *GraphViewer)
    {
        if (GraphViewer->objectName().isEmpty())
            GraphViewer->setObjectName(QStringLiteral("GraphViewer"));
        GraphViewer->resize(735, 496);
        gridLayout = new QGridLayout(GraphViewer);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        Graph = new QCustomPlot(GraphViewer);
        Graph->setObjectName(QStringLiteral("Graph"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Graph->sizePolicy().hasHeightForWidth());
        Graph->setSizePolicy(sizePolicy);

        gridLayout->addWidget(Graph, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        do_graph = new QPushButton(GraphViewer);
        do_graph->setObjectName(QStringLiteral("do_graph"));

        horizontalLayout->addWidget(do_graph);

        Refresh = new QPushButton(GraphViewer);
        Refresh->setObjectName(QStringLiteral("Refresh"));

        horizontalLayout->addWidget(Refresh);

        Cbox = new QComboBox(GraphViewer);
        Cbox->setObjectName(QStringLiteral("Cbox"));

        horizontalLayout->addWidget(Cbox);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);


        retranslateUi(GraphViewer);

        QMetaObject::connectSlotsByName(GraphViewer);
    } // setupUi

    void retranslateUi(QWidget *GraphViewer)
    {
        GraphViewer->setWindowTitle(QApplication::translate("GraphViewer", "Form", 0));
        do_graph->setText(QApplication::translate("GraphViewer", "Graph", 0));
        Refresh->setText(QApplication::translate("GraphViewer", "Refresh", 0));
    } // retranslateUi

};

namespace Ui {
    class GraphViewer: public Ui_GraphViewer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAPHVIEWER_H
