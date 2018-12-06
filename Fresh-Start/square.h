#ifndef SQUARE_H
#define SQUARE_H
#include <QString>

#include <Qt>
#include <QPainter>
#include <QRadialGradient>
#include <QString>
#include <QMap>

#include "shape.h"


/*!
* square class that inherits from the shape class
*/
class Square : public Shape
{
public:


    /*!
    * square constructor that creates and object of type square
    */
    Square(const QMap<QString,QString> &, QPaintDevice* );

    /*!
    * destructor for the square type that deletes all data related
    */
    ~Square() override {}

    /*!
    * draws the square shape
    */
    void draw() override;

    /*!
    * moves the square shape
    */
    void move(const int translate_x, const int translate_y) override;

    /*!
    * returns the perimeter of square
    */
    double perimeter() override;

    /*!
    * returns the area of square
    */
    int area() override;
};

#endif //Square
