#include "polyline.h"
#include <cmath>
#include <QMap>
#include <QStringList>
#include <QPainter>
#include <QPoint>
#include <QVector>
Polyline::Polyline(std::string id, shapeType shape, QPaintDevice* device, QVector<QPoint> points)
    : Shape(id, shape, device)
{
    //do contructor things
}

void Polyline::draw()
{
    /*
    getQPainter().begin(getQDevice());
    setStyles();
    QStringList words = props["ShapeDimensions"].split(", ");
    QVector<QPoint> points;
    drawIdentifier(words[0].toInt(),words[1].toInt());
    int npoints =0;
    for(int i =0; i<words.size();npoints++){
        points.push_back({words[i].toInt(),words[i+1].toInt()});
        i+=2;
    }
    getQPainter().drawPolyline(points.data(),npoints);
    getQPainter().end();
    */
}



void Polyline::move(const int translate_x, const int translate_y)
{
    //DO nothing now
    return;
}

double Polyline::perimeter()
{

}

double Polyline::area()
{
    return -1;
}
