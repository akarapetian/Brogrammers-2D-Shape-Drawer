#include "ellipse.h"
#include <cmath>
#include <QMap>
#include <QStringList>
#include <QPainter>
#include <QPoint>
#include <QRect>
#ifndef M_PI
#define M_PI (3.14159265358979323846)
#endif
Ellipse::Ellipse(std::string id, shapeType shape, QPaintDevice* device, QPoint topLeft, int a, int b)
    : Shape(id, shape, device)
{
}

void Ellipse::draw()
{
    /*
    getQPainter().begin(getQDevice());
    setStyles();
    QStringList words = props["ShapeDimensions"].split(", ");
    QRect rect(words[0].toInt(), words[1].toInt(),words[2].toInt(),words[3].toInt());
    drawIdentifier(words[0].toInt(),words[1].toInt());
    getQPainter().drawEllipse(rect);
    getQPainter().end();
    */

}


void Ellipse::move(const int translate_x, const int translate_y)
{
    //DO nothing now
    return;
}

double Ellipse::perimeter()
{
    //QStringList words = props["ShapeDimensions"].split(", ");
    //return  2 * M_PI * words[2].toInt();
}

double Ellipse::area()
{
    //QStringList words = props["ShapeDimensions"].split(", ");
    //return M_PI * words[2].toInt() * words[2].toInt();
}
