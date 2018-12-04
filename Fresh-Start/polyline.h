#ifndef POLYLINE_H
#define POLYLINE_H
#include <QString>

#include <Qt>
#include <QPainter>
#include <QRadialGradient>
#include <QString>
#include <QMap>

#include "shape.h"


class Polyline : public Shape
{
public:

    Polyline(const QMap<QString,QString> &, QPaintDevice* );

    ~Polyline() override {}

    void draw() override;
    void move(const int translate_x, const int translate_y) override;
    double perimeter() override;
    int area() override;
};

#endif // LINE_H
