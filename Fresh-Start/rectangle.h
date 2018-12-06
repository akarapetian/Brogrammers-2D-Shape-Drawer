#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <QString>

#include <Qt>
#include <QPainter>
#include <QRadialGradient>
#include <QString>
#include <QMap>

#include "shape.h"


/*!
* rectangle class that inherits from the shape class
*/
class Rectangle : public Shape
{
public:

    /*!
    * constructor for the rectangle object that creates a rectangle object
    */
    Rectangle(const QMap<QString,QString> &, QPaintDevice* );

    /*!
    * destructor for the rectangle object that destroys all data related
    */
    ~Rectangle() override {}

    /*!
    * draws the circle shape
    */
    void draw() override;

    /*!
    * moves the circle shape
    */
    void move(const int translate_x, const int translate_y) override;

    /*!
    * returns the perimeter of the rectangle
    */
    double perimeter() override;

    /*!
    * returns the area of the rectangle
    */
    int area() override;
};

#endif // LINE_H
