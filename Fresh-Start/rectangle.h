#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <QString>

#include <Qt>
#include <QPainter>
#include <QRadialGradient>
#include <QString>
#include <QMap>

#include "shape.h"


class Rectangle : public Shape
{
public:

    Rectangle(const QMap<QString,QString> &, QPaintDevice* );

    ~Rectangle() override {}

    void draw() override;
    void move(const int translate_x, const int translate_y) override;
    double perimeter() override;
    int area() override;
};

#endif // LINE_H
