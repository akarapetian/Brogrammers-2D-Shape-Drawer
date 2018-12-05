#include "renderarea.h"
#include <QTextStream>
#include <QPainter>
#include <QVector>
#include <iostream>
#include "utilities.cpp"


renderArea::renderArea(QWidget *parent)
    : QWidget(parent)
{
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);

    shapes = Utilities::readShapes(this);

    //this will show if the parser is populating the shapes vector, it is not working currently, (why nothing is drawing)
    QTextStream(stdout) << "size of shapes vector: " << shapes.size()  << endl;

}


void renderArea::paintEvent(QPaintEvent * /* event */)
{
    for(int i=0; i < shapes.size(); i++)
    {
        shapes[i]->draw();
    }
}

vector<Shape *> * renderArea::getShapes()
{
    return &shapes;
}



void renderArea::addShape()
{
    //shapes.push_back();
}
