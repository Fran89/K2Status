#include "graphviewer.h"
#include "ui_graphviewer.h"

GraphViewer::GraphViewer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GraphViewer)
{
    ui->setupUi(this);
}

GraphViewer::~GraphViewer()
{
    delete ui;
}

void GraphViewer::update_archive(QList<stninfo> arc){
    Archive = arc;
    //Populate the spinbox
    for(int i=0; i < Archive.length(); i++){
        ui->Cbox->addItem(Archive.at(i).Stat);
    }
}
