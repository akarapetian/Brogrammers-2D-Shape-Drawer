#ifndef POLYGON_H
#define POLYGON_H

#include <string>
#include <vector>
#include <Qt>
#include <QPainter>
#include <QRadialGradient>
#include "shape.h"

class Polygon : public Shape
{
public:
    Polygon(std::string id, shapeType shape, QPaintDevice* device, QVector<QPoint> points);
    ~Polygon() override {}

    void draw() override;
    void move(const int translate_x, const int translate_y) override;
    double perimeter() override;
    double area() override;
};

#endif // POLYGON_H
