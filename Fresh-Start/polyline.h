#ifndef POLYLINE_H
#define POLYLINE_H
#include <QString>

#include <Qt>
#include <QPainter>
#include <QRadialGradient>
#include <QString>
#include <QMap>

#include "shape.h"

/*!
* polyline class that inherits from the shape class
*/
class Polyline : public Shape
{
public:

    /*!
    * constructor for the polyline object
    */
    Polyline(const QMap<QString,QString> &, QPaintDevice* );

    /*!
    * destructor for the polyine object and related data
    */
    ~Polyline() override {}

    /*!
    * draws the circle shape
    */
    void draw() override;

    /*!
    * moves the circle shape
    */
    void move(const int translate_x, const int translate_y) override;

    /*!
    * returns the perimeter of the polyline, but it has no perimeter, so it returns nothing
    */
    double perimeter() override;

    /*!
    * returns the area of the polyline, but it has no area, so it returns nothing
    */
    int area() override;
};

#endif // LINE_H
