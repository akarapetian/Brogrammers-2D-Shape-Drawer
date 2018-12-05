#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QBrush>
#include <QPen>
#include <QPixmap>
#include <QWidget>
#include "shape.h"

#include "vector.h"
//! [0]
class renderArea : public QWidget
{

public:

    renderArea(QWidget *parent = 0);
    vector<Shape *> * getShapes();
    ~renderArea() {}

    void addShape();

public slots:

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    vector<Shape *> shapes;
};
//! [0]

#endif // RENDERAREA_H
