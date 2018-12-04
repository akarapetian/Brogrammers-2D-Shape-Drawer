#include "circle.h"
#include <cmath>
#include <QMap>
#include <QStringList>
#include <QPainter>
#include <QPoint>
#include <QRect>
#ifndef M_PI
#define M_PI (3.14159265358979323846)
#endif
Circle::Circle(const QMap<QString,QString> & props, QPaintDevice* device): Shape( props, device)
{
}

void Circle::draw()
{
    getQPainter().begin(getQDevice());
    setStyles();
    QStringList words = props["ShapeDimensions"].split(", ");
    QRect rect(words[0].toInt(), words[1].toInt(),words[2].toInt(),words[2].toInt());
    drawIdentifier(words[0].toInt(),words[1].toInt());
    getQPainter().drawEllipse(rect);
    getQPainter().end();
}


void Circle::move(const int translate_x, const int translate_y)
{
    //DO nothing now
    return;
}

double Circle::perimeter()
{
    QStringList words = props["ShapeDimensions"].split(", ");
    return  2 * M_PI * words[2].toInt();
}

int Circle::area()
{
    QStringList words = props["ShapeDimensions"].split(", ");
    return M_PI * words[2].toInt() * words[2].toInt();
}
