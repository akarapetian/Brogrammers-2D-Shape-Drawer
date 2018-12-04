#ifndef SQUARE_H
#define SQUARE_H
#include <QString>

#include <Qt>
#include <QPainter>
#include <QRadialGradient>
#include <QString>
#include <QMap>

#include "shape.h"


class Square : public Shape
{
public:

    Square(const QMap<QString,QString> &, QPaintDevice* );

    ~Square() override {}

    void draw() override;
    void move(const int translate_x, const int translate_y) override;
    double perimeter() override;
    int area() override;
};

#endif //Square
