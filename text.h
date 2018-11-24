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
    Text(const QMap<QString,QString> & styles, QPaintDevice* device);
    void draw() override;
    double perimeter() override;
    int area() override;
    void move(const int translateX, const int translateY);
    void setStyles() override;
};
#endif // TEXT_H
