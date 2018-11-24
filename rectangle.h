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

    Rectangle(std::string id, shapeType shape, QPaintDevice* device, QPoint topLeft, int length, int width);

    ~Rectangle() override {}

    void draw() override;
    void move(const int translate_x, const int translate_y) override;
    double perimeter() override;
    double area() override;
};

#endif // LINE_H
