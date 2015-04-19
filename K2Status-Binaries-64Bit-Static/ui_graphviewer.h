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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GraphViewer
{
public:
    QGridLayout *gridLayout;
    QWidget *Graph;

    void setupUi(QWidget *GraphViewer)
    {
        if (GraphViewer->objectName().isEmpty())
            GraphViewer->setObjectName(QStringLiteral("GraphViewer"));
        GraphViewer->resize(735, 496);
        gridLayout = new QGridLayout(GraphViewer);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        Graph = new QWidget(GraphViewer);
        Graph->setObjectName(QStringLiteral("Graph"));

        gridLayout->addWidget(Graph, 0, 0, 1, 1);


        retranslateUi(GraphViewer);

        QMetaObject::connectSlotsByName(GraphViewer);
    } // setupUi

    void retranslateUi(QWidget *GraphViewer)
    {
        GraphViewer->setWindowTitle(QApplication::translate("GraphViewer", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class GraphViewer: public Ui_GraphViewer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAPHVIEWER_H
