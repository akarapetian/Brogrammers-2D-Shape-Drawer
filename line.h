#ifndef LINE_H
#define LINE_H
#include <string>

#include <Qt>
#include <QPainter>
#include <QRadialGradient>

#include "shape.h"


class Line : public Shape
{
public:

    Line(std::string id, shapeType shape, QPaintDevice* device, QPoint begin, QPoint end);

    ~Line() override {}

    void set_points(const QPoint begin, const QPoint end);

    void draw() override;
    void move(const int translate_x, const int translate_y) override;
    double perimeter() override;
    double area() override;

private:
    QPoint point_begin;
    QPoint point_end;
};

#endif // LINE_H
