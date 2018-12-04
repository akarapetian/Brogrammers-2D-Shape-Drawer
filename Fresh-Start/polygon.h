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
    Polygon(const QMap<QString,QString> & props, QPaintDevice* device);
    ~Polygon() override {}

    void draw() override;
    void move(const int translate_x, const int translate_y) override;
    double perimeter() override;
    int area() override;
};

#endif // POLYGON_H
