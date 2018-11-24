/*
#ifndef TEXT_H
#define TEXT_H
#include "shape.h"

class Text: public Shape
{
private:
    QString textString;
    int textAlignment(const QString &align);
    int getFontStyle(const QString &weight);
    int getWeight(const QString &weight);

public:
    Text(std::string id, shapeType shape, QPaintDevice* device); //have to add a bunch more parameters
    void draw() override;
    double perimeter() override;
    double area() override;
    void move(const int translateX, const int translateY);
    void setStyles() override;
};
#endif // TEXT_H
*/
