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

#include <math.h>

/*!
* an abstract base class for a shape
*/
class Shape
{

public:
    //Supported Shape types
    /*!
    * enum to differentiate the types of shapes
    */
    enum class shapeType {line, polyline, polygon, rectangle, ellipse, text};

    /*!
    * shape constructor that is used in the derived classes constructors
    */
    Shape(const QMap<QString,QString> & styles, QPaintDevice* device);

    /*!
    * virtual destructor due to virtual methods
    */
    virtual ~Shape() {}

    /*!
    * sets the shapeType
    */
    void setShape(shapeType shape);

    /*!
    * sets the style of the shape
    */
    void virtual setStyles();

    /*!
    * sets the default style of the shape
    */
    void defaultStyle();

    /*!
    * draws the shape, but since it is an abstract class, it doesn't do anything here
    */
    virtual void draw() = 0;

    /*!
    * moves the shape, but since it is an abstract class, it doesn't do anything here
    */
    virtual void move(const int translateX, const int translateY) = 0;

    /*!
    * returns the perimeter of the shape, but doesn't apply here
    */
    virtual double perimeter() = 0;

    /*!
    * returns the area of the shape, but doesn't apply here
    */
    virtual int area() = 0;

    /*!
    * outputs the text
    */
    void drawText(const int x,const int y, QString text);

    /*!
    * outputs the unique shape id
    */
    void drawIdentifier(const int x, const int y);

    /*!
    * updates the mapping
    */
    void modify(const QString&, const QString&);

    /*!
    * returns the shape id
    */
    QString getId();

    /*!
    * returns the map
    */
    QMap<QString,QString>& getDictionary();


    /*!
    * integer variable that stores the previous input for translating in the horizontal direction
    */
    int prevTranslate_x;

    /*!
    * integer variable that stores the previous input for translating in the vertical direction
    */
    int prevTranslate_y;
protected:

    /*!
    * returns the QPainter object
    */
    QPainter& getQPainter();

    /*!
    * returns the QDevice object
    */
    QPaintDevice * getQDevice();

    /*!
    * props variable for the QMap
    */
    QMap<QString,QString> props;

private:

    /*!
    * returns the pen
    */
    QPen&  getPen() ;

    /*!
    * returns the brush
    */
    QBrush& getBrush() ;

    /*!
    * sets the pen color
    */
    void setPenColor();

    /*!
    * sets the pen width
    */
    void setPenWidth();

    /*!
    * sets the pen style
    */
    void setPenStyle();

    /*!
    * sets the pen cap style
    */
    void setPenCapStyle();

    /*!
    * sets the pen join style
    */
    void setPenJoinStyle();

    /*!
    * sets the brush color
    */
    void setBrushColor();

    /*!
    * sets the brush style
    */
    void setBrushStyle();

    /*!
    * activates the styles
    */
    void activateStyles();

    /*!
    * brush variable of type QBrush
    */
    QBrush brush;

    /*!
    * pen variable of type QPen
    */
    QPen pen;

    /*!
    * qpainter variable of type QPainter
    */
    QPainter qpainter;

    /*!
    * device variable of type QPaintDevice
    */
    QPaintDevice* device;

    /*!
    * identifier variable for type QString
    */
    QString identifier;

};

#endif /* Shape_h */
