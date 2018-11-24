#ifndef SHAPE_H
#define SHAPE_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>

#include <QPainter>
#include <QPen>

#include "vector.h"

//make shape derive form Qwidget to see if i can draw


class Shape
{

public:
    //Supported Shape types
    enum class shapeType {line, polyline, polygon, rectangle, ellipse, text};

    Shape(std::string id, shapeType shape, QPaintDevice* device);
    virtual ~Shape() {}

    shapeType getShape() const;
    const QPen& getPen() const;
    const QBrush& getBrush() const;

    void setShape(shapeType shape);
    void setPen(Qt::GlobalColor, int width, Qt::PenStyle, Qt::PenCapStyle, Qt::PenJoinStyle);
    void setPen(Qt::GlobalColor);
    void setBrush(Qt::GlobalColor, Qt::BrushStyle);
    void defaultStyle();
    void drawRect(int width, int height);

    virtual void draw() = 0;
    virtual void move(const int translateX, const int translateY) = 0;
    virtual double perimeter() = 0;
    virtual double area() = 0;

    void drawText(const int x,const int y, std::string text);
    void drawIdentifier(const int x, const int y);
protected:
    QPainter& getQPainter();



private:
    QPaintDevice* paintDevice;
    QPainter qpainter;

    std::string identifier;
    shapeType shape;
    QPen pen;
    QBrush brush;
};

#endif
