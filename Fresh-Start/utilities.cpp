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

        //this block finds the correct filepath to shapes.txt
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



    static vector<Shape*> selectionSort(QPaintDevice* device, bool (*comparisonFcn)(Shape*,Shape*))
    {

        vector<Shape*> newVector = readShapes(device);

        // Step through each node of the vector
        for (int i = 0; i < newVector.size(); ++i)
        {
            int bestIndex = i;

            for (int currentIndex = i + 1; currentIndex < newVector.size(); ++currentIndex)
            {
                // If the current element is smaller/larger than our previously found smallest
                if (comparisonFcn(newVector[currentIndex], newVector[currentIndex])) // COMPARISON DONE HERE
                    // This is the new smallest/largest number for this iteration
                    bestIndex = currentIndex;
            }

            // Swap our start element with our best element
            std::swap(newVector[i], newVector[bestIndex]);
        }

        return newVector;
    }

    static bool id(Shape* prev, Shape* current)
    {
        return prev->getId() < current->getId();
    }

    static bool perimeter(Shape* prev, Shape* current)
    {
        return prev->perimeter() < current->perimeter();
    }

    static bool area(Shape* prev, Shape* current)
    {
        return prev->area() < current->area();
    }
};
