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

    Ellipse(const QMap<QString,QString> &, QPaintDevice* );

    ~Ellipse() override {}

    void draw() override;
    void move(const int translate_x, const int translate_y) override;
    double perimeter() override;
    int area() override;
};

#endif // LINE_H
