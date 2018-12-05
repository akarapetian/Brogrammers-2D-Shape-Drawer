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
    QStringList words = props["ShapeDimensions"].split(", ");

    QString newDimensions;

    //read the positions in
    for(int i = 0; i < words.size(); i++)
    {
        if(i % 2 == 0)
        {
            //if even number
            words[i] = QString::number(words[i].toInt() + (translate_x - prevTranslate_x));
        }
        else
        {
            //if odd number
            words[i] = QString::number(words[i].toInt() + (translate_y - prevTranslate_y));
        }

        //this if statement makes sure that no extra comma is added to the end
        if(i < words.size() - 1)
        {
           newDimensions += words[i] + ", ";
        }
        else
        {
            newDimensions += words[i];
        }

        QTextStream(stdout) << newDimensions  << endl;
    }

    prevTranslate_x = translate_x;
    prevTranslate_y = translate_y;

    props["ShapeDimensions"] = newDimensions;
    QTextStream(stdout) << props["ShapeDimensions"]  << endl;
}

double Line::perimeter()
{
    return  -1;
}

int Line::area()
{
    return -1;
}
