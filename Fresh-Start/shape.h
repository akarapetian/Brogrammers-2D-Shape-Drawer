#ifndef Shape_h
#define Shape_h

#include <Qt>
#include <QPainter>
#include <QPaintDevice>
#include <QRadialGradient>
#include <QPoint>
#include <QMap>
#include <QString>
#include <QPen>
#include <QBrush>
#include <QColor>
#include <QFont>

#include <QTextStream>
#include <iostream>

class Shape
{

public:
    //Supported Shape types
    enum class shapeType {line, polyline, polygon, rectangle, ellipse, text};

    Shape(const QMap<QString,QString> & styles, QPaintDevice* device);
    virtual ~Shape() {}

    void setShape(shapeType shape);
    void virtual setStyles();
    void defaultStyle();

    virtual void draw() = 0;
    virtual void move(const int translateX, const int translateY) = 0;
    virtual double perimeter() = 0;
    virtual int area() = 0;

    void drawText(const int x,const int y, QString text);
    void drawIdentifier(const int x, const int y);
    void modify(const QString&, const QString&);
    QString getId();
    QMap<QString,QString>& getDictionary();

    int prevTranslate_x;
    int prevTranslate_y;

protected:
    QPainter& getQPainter();
    QPaintDevice * getQDevice();
    QMap<QString,QString> props;

private:
    QPen&  getPen() ;
    QBrush& getBrush() ;

    void setPenColor();
    void setPenWidth();
    void setPenStyle();
    void setPenCapStyle();
    void setPenJoinStyle();
    void setBrushColor();
    void setBrushStyle();
    void activateStyles();


    QBrush brush;
    QPen pen;
    QPainter qpainter;
    QPaintDevice* device;
    QString identifier;

};

#endif /* Shape_h */
