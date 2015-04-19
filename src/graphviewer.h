#ifndef GRAPHVIEWER_H
#define GRAPHVIEWER_H
#include <QWidget>
#include "stninfo.h"

namespace Ui {
class GraphViewer;
}

class GraphViewer : public QWidget
{
    Q_OBJECT

public:
    explicit GraphViewer(QWidget *parent = 0);
    void set_archive(QList<stninfo>);
    ~GraphViewer();

public slots:
    void update_archive(QList<stninfo>);

private:
    QList<stninfo> Archive;
    Ui::GraphViewer *ui;
};

#endif // GRAPHVIEWER_H
