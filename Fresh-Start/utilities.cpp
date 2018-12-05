#include <QFile>
#include <QMessageBox>
#include <QIODevice>
#include <QString>
#include <QStringList>
#include <QTextStream>
#include <vector>
#include <QMap>
#include <QVector>
#include <QPaintDevice>
#include "shape.h"
#include "ellipse.h"
#include "circle.h"
#include "line.h"
#include "polygon.h"
#include "polyline.h"
#include "rectangle.h"
#include "square.h"
#include "text.h"
#include <QDir>
#include "vector.h"


class Utilities{
public:
    static vector<QMap<QString,QString>> readShapesFile(){
        QFile file("/home/cs1c/Brogrammers-2D-Shape-Drawer/Fresh-Start/shapes.txt");
        vector<QMap<QString,QString>> vec;
        QMap<QString,QString> dictionary;

        if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
            QMessageBox::information(0, "error", file.errorString());

        else
        {
            QTextStream in(&file);

            while(!in.atEnd()) {

                QString line = in.readLine();
                if(line.isEmpty())
                {
                    if(dictionary.empty())
                        continue;
                    vec.push_back(dictionary);
                    dictionary.clear();
                }
                else
                {
                    QStringList fields = line.split(": ");
                    dictionary[fields[0]]=fields[1];
                }
            }
            file.close();

        }
        return vec;
    }

    static vector<Shape *> readShapes(QPaintDevice* device){
        vector<QMap<QString,QString>> shapesRead = readShapesFile();
        vector<Shape *> newVector;

        for(int i = 0; i < shapesRead.size(); i++) {


            if(shapesRead[i]["ShapeType"].indexOf("Text")!=-1){
                newVector.push_back(new Text(shapesRead[i], device));
            }
            if(shapesRead[i]["ShapeType"].indexOf("Rectangle")!=-1){
                newVector.push_back(new Rectangle(shapesRead[i], device));
            }
            if(shapesRead[i]["ShapeType"].indexOf("Polygon")!=-1){
                newVector.push_back(new Polygon(shapesRead[i], device));
            }
            if(shapesRead[i]["ShapeType"].indexOf("Line")!=-1){
                newVector.push_back(new Line(shapesRead[i], device));
            }
            if(shapesRead[i]["ShapeType"].indexOf("Square")!=-1){
                newVector.push_back(new Square(shapesRead[i], device));
            }
            if(shapesRead[i]["ShapeType"].indexOf("Polyline")!=-1){
                newVector.push_back(new Polyline(shapesRead[i], device));
            }
            if(shapesRead[i]["ShapeType"].indexOf("Circle")!=-1){
                newVector.push_back(new Circle(shapesRead[i], device));
            }
            if(shapesRead[i]["ShapeType"].indexOf("Ellipse")!=-1){
                newVector.push_back(new Ellipse(shapesRead[i], device));
            }
        }

        return newVector;
    }
};
