#include "rectangle.h"
#include <cmath>
#include <QMap>
#include <QStringList>
#include <QPainter>
#include <QPoint>
#include <QRect>

Rectangle::Rectangle(const QMap<QString,QString> & props, QPaintDevice* device): Shape( props, device)
{
}

void Rectangle::draw()
{
    getQPainter().begin(getQDevice());
    setStyles();
    QStringList words = props["ShapeDimensions"].split(", ");
    drawIdentifier(words[0].toInt(),words[1].toInt());
    getQPainter().drawRect(QRect(words[0].toInt(),words[1].toInt(),words[2].toInt(),words[3].toInt()));
    getQPainter().end();
}


void Rectangle::move(const int translate_x, const int translate_y)
{
    //DO nothing now
    return;
}

double Rectangle::perimeter()
{
    QStringList words = props["ShapeDimensions"].split(", ");
    return  std::abs(words[0].toInt()-words[2].toInt())*2+std::abs(words[1].toInt()-words[3].toInt())*2;
}

int Rectangle::area()
{
    QStringList words = props["ShapeDimensions"].split(", ");
    return std::abs(words[0].toInt()-words[2].toInt())*std::abs(words[1].toInt()-words[3].toInt());
}
