//parser

#include <iostream>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

#include "shape.h"
#include "vector.h"

Shape* readShapesFile()
{
    vector<Shape> shapeVector();

    QFile file("shapes.txt");

    if(!file.open(QFile::ReadOnly | QFile::Text))
    {
        //QMessageBox::warning(this,"warning","file not open");
    }
    else
    {
       /*
        QTextStream in(&file);
        while(!in.atEnd())
        {
            QString id = in.readLine();
            QString type = in.readLine();

            if(type == "Line")
            {
                QPoint p1;
                QPoint p2;


                in >> p1.rx >> p1.ry >> p2.rx >> p2.ry;
            }
            else if(type == "Polyline" || type == "Polygon")
            {

                //need to figure out a way to make this dynamic

                QPoint p1;
                QPoint p2;
                QPoint p3;
                QPoint p4;

                in >> p1.rx >> p1.ry >> p2.rx >> p2.ry >> p3.rx >> p3.ry >> p4.rx >> p4.ry;

                QString line = in.readLine();

                QString point = '';

                line.mid(point.size(), )



                vector<Qpoint> points;
                int count = 0;


            }
            else if(type == "Rectangle")
            {
                QPoint p;
                int length;
                int width;

                in >> p.rx >> p.ry >> length >> width;
            }
            else if(type == "Square")
            {
                QPoint p;
                int length;

                in >> p.rx >> p.ry >> length;
            }
            else if(type == "Ellipse")
            {
                QPoint p;
                int a; //semi major axis
                int b; //semi minor axis

                in >> p.rx >> p.ry >> a >> b;
            }
            else if(type == "Circle")
            {
                QPoint p;
                int r; //radius

                in >> p.rx >> p.ry >> r;
            }
            else if(type == "Text")
            {
                QPoint p;
                int length;
                int width;

                in >> p.rx >> p.ry >> length >> width;
            }
        }

    }

    //EVERY type has an id and type

    //line - has everything except for brushcolor/brushstyle
    //polyline, polygon, rectangle, square, ellipse, circle - have everything
    //text - has a completely different set of things


    QPoint p1;
    QPoint p2;
    QPoint p3;
    QPoint p4;

    QPoint topLeftPoint;

    int length;
    int width;

    int a; //major axis
    int b; //minor axis

    int r; //radius

    if(type == "Text")
    {
        //do text stuff
    }
    else
    {
        //do everything



        if(type != "Line")
        {
            //do brush things
        }
    }


    fin.close();






    */








    //shapeVector.push_back(new Text())

    //shapeVector.push_back(new Line(std::string id, shapeType shape, QPaintDevice* device, QPoint begin, QPoint end));


    }

}
