#include "square.h"
#include <cmath>
#include <QMap>
#include <QStringList>
#include <QPainter>
#include <QPoint>
#include <QRect>

Square::Square(const QMap<QString,QString> & props, QPaintDevice* device): Shape( props, device)
{
}

void Square::draw()
{
    getQPainter().begin(getQDevice());
    setStyles();
    QStringList words = props["ShapeDimensions"].split(", ");
    drawIdentifier(words[0].toInt(),words[1].toInt());
    getQPainter().drawRect(QRect (words[0].toInt(), words[1].toInt(), words[2].toInt() , words[2].toInt() ));
    getQPainter().end();
}


void Square::move(const int translate_x, const int translate_y)
{
    //DO nothing now
    return;
}

double Square::perimeter()
{
    QStringList words = props["ShapeDimensions"].split(", ");
    return  2;//std::sqrt((words[0].toInt()-words[2].toInt())*(words[0].toInt()-words[2].toInt())+(words[3].toInt()-words[1].toInt())*(words[3].toInt()-words[1].toInt())+0.0);
}

int Square::area()
{
    QStringList words = props["ShapeDimensions"].split(", ");
    return  2;//std::sqrt((words[0].toInt()-words[2].toInt())*(words[0].toInt()-words[2].toInt())+(words[3].toInt()-words[1].toInt())*(words[3].toInt()-words[1].toInt())+0.0)*std::sqrt((words[0].toInt()-words[2].toInt())*(words[0].toInt()-words[2].toInt())+(words[3].toInt()-words[1].toInt())*(words[3].toInt()-words[1].toInt())+0.0);
}
