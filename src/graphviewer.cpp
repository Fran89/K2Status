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
    ui->Cbox->clear();
    for(int i=0; i < Archive.length(); i++){
        ui->Cbox->addItem(Archive.at(i).Stat);
    }
}

void GraphViewer::on_do_graph_clicked()
{
    QString STA;
    stninfo Temp;
    QVector<qreal> time;
    int idx;
    Temp.setup(STA);
    STA = ui->Cbox->currentText();
    idx = Archive.indexOf(Temp);
    for (int i = 0; i < Archive.at(idx).Time.length(); i++){
        double timetemp;
        timetemp = Archive.at(idx).Time.at(i);
        time.append(timetemp);

    }
    ui->Graph->addGraph();
    QPen pen;
    pen.setColor(QColor(0, 0, 255, 200));
    ui->Graph->graph()->setLineStyle(QCPGraph::lsLine);
    ui->Graph->graph()->setPen(pen);

    ui->Graph->graph()->setData(time, Archive.at(idx).Temperature);
    //ui->Graph->graph()->addData(time, Archive.at(idx).Voltage);

    // configure bottom axis to show date and time instead of number:
    ui->Graph->xAxis->setTickLabelType(QCPAxis::ltDateTime);
    ui->Graph->xAxis->setDateTimeFormat("d\nMM");

}
