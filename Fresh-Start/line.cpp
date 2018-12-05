#include "line.h"
#include <cmath>
#include <QMap>
#include <QStringList>
#include <QPainter>
#include <QPoint>

Line::Line(const QMap<QString,QString> & props, QPaintDevice* device): Shape( props, device)
{
}

void Line::draw()
{
    getQPainter().begin(getQDevice());
    setStyles();
    QStringList words = props["ShapeDimensions"].split(", ");
    drawIdentifier(words[0].toInt(),words[1].toInt());
    getQPainter().drawLine(QPoint(words[0].toInt(),words[1].toInt()), QPoint(words[2].toInt(),words[3].toInt()));
    getQPainter().end();
}


void Line::move(const int translate_x, const int translate_y)
{
    //DO nothing now
    return;
}

double Line::perimeter()
{
    return  -1;
}

int Line::area()
{
    return -1;
}
