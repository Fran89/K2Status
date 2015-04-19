#ifndef GRAPTHVIEWER_H
#define GRAPTHVIEWER_H

#include <QWidget>

namespace Ui {
class GrapthViewer;
}

class GrapthViewer : public QWidget
{
    Q_OBJECT

public:
    explicit GrapthViewer(QWidget *parent = 0);
    ~GrapthViewer();

private:
    Ui::GrapthViewer *ui;
};

#endif // GRAPTHVIEWER_H
