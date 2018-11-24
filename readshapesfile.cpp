//parser

#include "vector.h"
#include "shape.h"

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
        QMessageBox::warning(this,"warning","file not open");
    }
    else
    {
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
                vector<Qpoint> points;

            }
        }

    }

    QTextStream in(&file);





    fin.close();

}
