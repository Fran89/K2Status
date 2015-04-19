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
        stninfo tmp;
        tmp = Archive.at(i);
        ui->Cbox->addItem(tmp.getName());
    }
}

void GraphViewer::on_do_graph_temp_clicked()
{
    stninfo station;
    int idx = 0;
    station.setup(ui->Cbox->currentText());
    idx = Archive.indexOf(station);

    ui->label->setText(station.getName());
    ui->Graph->clearGraphs();
    ui->Graph->addGraph();

    ui->Graph->graph()->setPen(QPen(Qt::blue));
    //ui->Graph->graph()->setBrush(QBrush(QColor(240, 255, 200)));
    ui->Graph->graph()->setData(Archive.at(idx).Time,
                                Archive.at(idx).Temperature);
    ui->Graph->xAxis->rescale();
    ui->Graph->yAxis->rescale();

    //ui->Graph->graph()->addData(time, Archive.at(idx).Voltage);

    // configure bottom axis to show date and time instead of number:
    ui->Graph->xAxis->setTickLabelType(QCPAxis::ltDateTime);
    ui->Graph->xAxis->setDateTimeFormat("d/MM/yyyy");

}

void GraphViewer::on_do_graph_volt_clicked()
{
    stninfo station;
    int idx = 0;
    station.setup(ui->Cbox->currentText());
    idx = Archive.indexOf(station);

    ui->label->setText(station.getName());
    ui->Graph->clearGraphs();
    ui->Graph->addGraph();

    ui->Graph->graph()->setPen(QPen(Qt::blue));
    //ui->Graph->graph()->setBrush(QBrush(QColor(240, 255, 200)));
    ui->Graph->graph()->setData(Archive.at(idx).Time,
                                Archive.at(idx).Voltage);
    ui->Graph->xAxis->rescale();
    ui->Graph->yAxis->rescale();

    // configure bottom axis to show date and time instead of number:
    ui->Graph->xAxis->setTickLabelType(QCPAxis::ltDateTime);
    ui->Graph->xAxis->setDateTimeFormat("d/MM/yyyy");

}
