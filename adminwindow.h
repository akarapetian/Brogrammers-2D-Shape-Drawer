#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include <QDialog>

#include <QGraphicsScene>

#include "vector.h"
#include "shape.h"
#include "ellipse.h"
#include "line.h"
#include "polygon.h"
#include "polyline.h"
#include "rectangle.h"
#include "text.h"


namespace Ui {
class adminWindow;
}

class adminWindow : public QDialog
{
    Q_OBJECT

public:
    explicit adminWindow(QWidget *parent = 0);
    ~adminWindow();


protected:
    void paintEvent(QPaintEvent *event) override;

private slots:

    void on_readFile_clicked();

private:
    Ui::adminWindow *ui;

    QPaintDevice *paintDevice;

    vector<Shape*> shapeVector;
};

#endif // ADMINWINDOW_H
