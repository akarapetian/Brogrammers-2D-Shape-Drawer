#ifndef LINE_H
#define LINE_H
#include <QString>

#include <Qt>
#include <QPainter>
#include <QRadialGradient>
#include <QString>
#include <QMap>

#include "shape.h"


class Line : public Shape
{
public:

    Line(const QMap<QString,QString> &, QPaintDevice* );

    ~Line() override {}

    void draw() override;
    void move(const int translate_x, const int translate_y) override;
    double perimeter() override;
    int area() override;
};

#endif // LINE_H
