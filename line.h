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

    Line(QPoint begin, QPoint end, shapeType shape, std::string id, QPaintDevice* device);

    ~Line() override {}

    void set_points(const QPoint begin, const QPoint end);

    void draw() override;
    void move(const int translate_x, const int translate_y) override;
    void perimeter() override;
    void area() override;

private:
    QPoint point_begin;
    QPoint point_end;
};

#endif // LINE_H
