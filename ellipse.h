#ifndef ELLIPSE_H
#define ELLIPSE_H
#include <QString>

#include <Qt>
#include <QPainter>
#include <QRadialGradient>
#include <QString>
#include <QMap>

#include "shape.h"


class Ellipse : public Shape
{
public:

    Ellipse(std::string id, shapeType shape, QPaintDevice* device, QPoint topLeft, int a, int b);

    ~Ellipse() override {}

    void draw() override;
    void move(const int translate_x, const int translate_y) override;
    double perimeter() override;
    double area() override;

private:


};

#endif // LINE_H
