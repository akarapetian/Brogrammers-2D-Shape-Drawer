#include "shape.h"
#include <QUuid>

Shape::Shape(std::string id , Shape::shapeType typeOfShape, QPaintDevice* device){
    shape = typeOfShape;
    if(id == "-1"){
        QUuid u=QUuid::createUuid();
        id = u.toString().toUtf8().constData();;
    }
    identifier = id;
    paintDevice = device;
}

Shape::shapeType Shape::getShape() const{
    return shape;
}

const QPen& Shape::getPen() const{
    return  pen;
}

const QBrush& Shape::getBrush() const{
    return  brush;
}

void Shape::setShape(shapeType newShape){
    shape = newShape;
}

void Shape::setPen(Qt::GlobalColor color, int width, Qt::PenStyle style, Qt::PenCapStyle cap, Qt::PenJoinStyle join){
    pen = QPen(color, width, style, cap, join);
}

void Shape::setPen(Qt::GlobalColor color){
    pen = QPen(color);

}

void Shape::setBrush(Qt::GlobalColor color, Qt::BrushStyle style){
    brush = QBrush(color, style);
}


void Shape::drawText(const int x, const int y, std::string drawText){
    qpainter.drawText(QPoint(x,y),QString::fromStdString(drawText) );
}

void Shape::drawIdentifier(const int x, const int y){
    drawText(x, y, identifier);
}

QPainter& Shape::getQPainter() {
    return qpainter;
}

void Shape::defaultStyle(){
    pen = QPen();
    pen.setStyle(Qt::DashDotLine);
    pen.setWidth(3);
    pen.setBrush(Qt::green);
    pen.setCapStyle(Qt::RoundCap);
    pen.setJoinStyle(Qt::RoundJoin);
    pen.setStyle(Qt::DashDotLine);
    pen.setWidth(3);
    pen.setBrush(Qt::green);
    pen.setCapStyle(Qt::RoundCap);
    pen.setJoinStyle(Qt::RoundJoin);
    QRadialGradient gradient(50, 50, 50, 50, 50);
    gradient.setColorAt(0, QColor::fromRgbF(0, 1, 0, 1));
    gradient.setColorAt(1, QColor::fromRgbF(0, 0, 0, 0));
    brush = gradient;
}
