#ifndef CIRCLE
#define CIRCLE
#include <QString>

#include <Qt>
#include <QPainter>
#include <QRadialGradient>
#include <QString>
#include <QMap>

#include "shape.h"

/*!
* class of type circle that inherits from shape class
*/
class Circle : public Shape
{
public:

    /*!
     * creates an object of type circle
     */

    Circle(const QMap<QString,QString> &, QPaintDevice* );

    /*!
    * destroys an object of type circle and all data related
    */
    ~Circle() override {}

    /*!
    * draws the circle shape
    */
    void draw() override;

    /*!
    * moves the circle shape
    */
    void move(const int translate_x, const int translate_y) override;

    /*!
    * returns the perimeter of the circle
    */
    double perimeter() override;

    /*!
    * returns the area of the circle
    */
    int area() override;
};

#endif // LINE_H
