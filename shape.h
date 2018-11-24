#ifndef SHAPE_H
#define SHAPE_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>

#include <QPainter>
#include <QPen>


class Shape
{

public:
    //Supported Shape types
    enum class shapeType {line, polyline, polygon, rectangle, ellipse, text};

    Shape(shapeType shape, std::string id = "-1", QPaintDevice* device = nullptr );
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
    virtual void perimeter() = 0;
    virtual void area() = 0;

    void drawText(const int x,const int y, std::string text);
    void drawIdentifier(const int x, const int y);
protected:
    QPainter& getQPainter();

private:
    QPaintDevice* device;
    QPainter qpainter;

    std::string identifier;
    shapeType shape;
    QPen pen;
    QBrush brush;
};

#endif
