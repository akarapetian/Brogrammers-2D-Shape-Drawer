#ifndef TEXT_H
#define TEXT_H
#include "shape.h"

/*!
* text class that inherits from the shape class
*/
class Text: public Shape
{
private:

    /*!
    * textString variable of type QString
    */
    QString textString;

    /*!
    * alligns the text
    */
    int textAlignment(const QString &align);

    /*!
    * returns the font style
    */
    int getFontStyle(const QString &weight);

    /*!
    * returns the weight
    */
    int getWeight(const QString &weight);

public:

    /*!
    * creates a text object
    */
    Text(const QMap<QString,QString> & styles, QPaintDevice* device);

    /*!
    * draws the text object
    */
    void draw() override;

    /*!
    * returns the perimeter of the text object, but since it is text, it has no perimeter
    */
    double perimeter() override;

    /*!
    * returns the area of the text object, but since it is text, it has no perimeter
    */
    int area() override;

    /*!
    * moves the text object
    */
    void move(const int translateX, const int translateY);

    /*!
    * sets the style of the text
    */
    void setStyles() override;
};
#endif // TEXT_H
