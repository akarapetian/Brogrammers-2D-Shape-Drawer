#include "line.h"

Line::Line(QPoint begin, QPoint end, shapeType shape, std::string id, QPaintDevice* device)
        : Shape(shape, id, device)
{
    point_begin = begin;
    point_end   = end;
}

void Line::set_points(const QPoint begin, const QPoint end)
{
    point_begin = begin;
    point_end   = end;
}


void Line::draw()
{
    getQPainter().drawLine(point_begin, point_end);
}


void Line::move(const int translate_x, const int translate_y)
{
    point_begin.rx() += translate_x;
    point_begin.ry() += translate_y;

    point_end.rx() += translate_x;
    point_end.ry() += translate_y;
}

void Line::perimeter()
{
    //not sure
}

void Line::area()
{
    //not sure
}
