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
Ellipse::Ellipse(const QMap<QString,QString> & props, QPaintDevice* device): Shape( props, device)
{
}

void Ellipse::draw()
{
    getQPainter().begin(getQDevice());
    setStyles();
    QStringList words = props["ShapeDimensions"].split(", ");
    QRect rect(words[0].toInt(), words[1].toInt(),words[2].toInt(),words[3].toInt());
    drawIdentifier(words[0].toInt(),words[1].toInt());
    getQPainter().drawEllipse(rect);
    getQPainter().end();
}


void Ellipse::move(const int translate_x, const int translate_y)
{
    QStringList words = props["ShapeDimensions"].split(", ");

    QString newDimensions;

    //read the positions in
    for(int i = 0; i < 2; i++)
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

        newDimensions += words[i] + ", ";

        QTextStream(stdout) << newDimensions  << endl;
    }

    newDimensions += words[2] + ", " + words[3];


    prevTranslate_x = translate_x;
    prevTranslate_y = translate_y;

    props["ShapeDimensions"] = newDimensions;
    QTextStream(stdout) << props["ShapeDimensions"]  << endl;

}

double Ellipse::perimeter()
{
    QStringList words = props["ShapeDimensions"].split(", ");
    return  2 * M_PI * sqrt(((words[2].toInt() * words[2].toInt()) + (words[3].toInt() * words[3].toInt()))/2);
}

int Ellipse::area()
{
    QStringList words = props["ShapeDimensions"].split(", ");
    return M_PI * words[2].toInt() * words[3].toInt();
}
