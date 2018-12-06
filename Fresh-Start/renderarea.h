#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QBrush>
#include <QPen>
#include <QPixmap>
#include <QWidget>
#include "shape.h"

#include "vector.h"

/*!
* renderArea class that inherits from QWidget that creates a rendering area for our shapes
*/
class renderArea : public QWidget
{

public:

    /*!
    * creates an object of renderArea that creates a window for the shapes to be rendered in
    */
    renderArea(QWidget *parent = 0);

    /*!
    * returns the shapes vector
    */
    vector<Shape *> * getShapes();

    /*!
    * destroys the renderArea
    */
    ~renderArea() {}

    /*!
    * adds a shape to the vector
    */
    void addShape();

public slots:

protected:
    /*!
    * calls the draw functions to output the shapes
    */
    void paintEvent(QPaintEvent *event) override;

private:
    /*!
    * vector for the shapes
    */
    vector<Shape *> shapes;
};


#endif // RENDERAREA_H
