#ifndef LINE_H
#define LINE_H
#include <QString>

#include <Qt>
#include <QPainter>
#include <QRadialGradient>
#include <QString>
#include <QMap>

#include "shape.h"

/*!
* line class that inherits from the shape class
*/
class Line : public Shape
{
public:

    /*!
    * constructor for line object
    */
    Line(const QMap<QString,QString> &, QPaintDevice* );

    /*!
    * destructor destroys all data related to the line object
    */
    ~Line() override {}

    /*!
    * draws the circle shape
    */
    void draw() override;

    /*!
    * moves the circle shape
    */
    void move(const int translate_x, const int translate_y) override;

    /*!
    * returns the perimeter of a line, however, a line doesn't have a perimeter
    */
    double perimeter() override;

    /*!
    * returns the area of line, however, it's a line, so it serves no purpose
    */
    int area() override;

};

#endif // LINE_H
