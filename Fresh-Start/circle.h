#ifndef CIRCLE
#define CIRCLE
#include <QString>

#include <Qt>
#include <QPainter>
#include <QRadialGradient>
#include <QString>
#include <QMap>

#include "shape.h"


class Circle : public Shape
{
public:

    Circle(const QMap<QString,QString> &, QPaintDevice* );

    ~Circle() override {}

    void draw() override;
    void move(const int translate_x, const int translate_y) override;
    double perimeter() override;
    int area() override;
};

#endif // LINE_H
