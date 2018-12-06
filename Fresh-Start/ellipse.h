#ifndef ELLIPSE_H
#define ELLIPSE_H
#include <QString>

#include <Qt>
#include <QPainter>
#include <QRadialGradient>
#include <QString>
#include <QMap>

#include "shape.h"

/*!
* class of ellipse shape that inherits from the shape class
*/
class Ellipse : public Shape
{
public:

    /*!
    * constructor to make ellipse object
    */
    Ellipse(const QMap<QString,QString> &, QPaintDevice* );

    /*!
    * destructor that deallocates and destroys all data related to ellipse
    */
    ~Ellipse() override {}

    /*!
    * draws the circle shape
    */
    void draw() override;

    /*!
    * moves the circle shape
    */
    void move(const int translate_x, const int translate_y) override;

    /*!
    * returns the perimeter of the ellipse
    */
    double perimeter() override;

    /*!
    * returns the area of the ellipse
    */
    int area() override;
};

#endif // LINE_H
