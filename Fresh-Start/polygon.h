#ifndef POLYGON_H
#define POLYGON_H

#include <string>
#include <vector>
#include <Qt>
#include <QPainter>
#include <QRadialGradient>
#include "shape.h"

/*!
* polygon class that inherits from the shape class
*/
class Polygon : public Shape
{
public:

    /*!
    * constructor for the polygon shape
    */
    Polygon(const QMap<QString,QString> & props, QPaintDevice* device);

    /*!
    * destructor for the polygon shape that destroys all data related
    */
    ~Polygon() override {}

    /*!
    * draws the circle shape
    */
    void draw() override;

    /*!
    * moves the circle shape
    */
    void move(const int translate_x, const int translate_y) override;

    /*!
    * returns the perimeter of the polygon
    */
    double perimeter() override;

    /*!
    * returns the area of the polygon
    */
    int area() override;
};

#endif // POLYGON_H
