#include "shape.h"
#include <QUuid>
#include <cmath>

Shape::Shape(const QMap<QString,QString> & styles, QPaintDevice* device):props(styles), brush(), pen(), qpainter(), device(device){

    if(props["ShapeId"] == "-1"){
        QUuid u=QUuid::createUuid();
        props["ShapeId"] = u.toString();
    }
    identifier = props["ShapeId"];

    prevTranslate_x = 0;
    prevTranslate_y = 0;
}


QPen& Shape::getPen(){
    return  pen;
}

QBrush& Shape::getBrush(){
    return  brush;
}

void Shape::drawText(const int x, const int y, QString drawText){
    qpainter.drawText(QPoint(x,y), drawText);
}

void Shape::drawIdentifier(const int x, const int y){
    drawText(x+10, y-15, identifier);
}

QPainter& Shape::getQPainter() {
    return qpainter;
}

QPaintDevice * Shape::getQDevice() {
    return device;
}

QString Shape::getId(){
    return identifier;
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

void Shape::setStyles(){
    if(props.contains("PenColor"))
    setPenColor();
    if(props.contains("PenWidth"))
    setPenWidth();
    if(props.contains("PenStyle"))
    setPenStyle();
    if(props.contains("PenCapStyle"))
    setPenCapStyle();
    if(props.contains("PenJoinStyle"))
    setPenJoinStyle();
    if(props.contains("BrushColor"))
    setBrushColor();
    if(props.contains("BrushStyle"))
    setBrushStyle();
    activateStyles();
}

void Shape::activateStyles(){
    getQPainter().setPen(pen);
    getQPainter().setBrush(brush);;
}

void Shape::setPenColor(){
    pen.setColor(QColor(props.value("TextColor")));
}

void Shape::setPenWidth(){
    pen.setWidth(props["PenWidth"].toInt());
}

void Shape::setPenStyle(){
    QMap<QString, Qt::PenStyle> map;
    map["SolidLine"]=Qt::SolidLine;
    map["DashLine"]=Qt::DashLine;
    map["DotLine"]=Qt::DotLine;
    map["DashDotLine"]=Qt::DashDotLine;
    map["DashDotDotLine"]=Qt::DashDotDotLine;
    map["NoPen"] =Qt::NoPen;
    pen.setStyle(map[props.value("PenStyle")]);
}

void Shape::setPenCapStyle(){
    QMap<QString, Qt::PenCapStyle> map;
    map["FlatCap"]=Qt::FlatCap;
    map["SquareCap"]=Qt::SquareCap;
    map["RoundCap"]=Qt::RoundCap;
    pen.setCapStyle(map[props.value("PenCapStyle")]);
}

void Shape::setPenJoinStyle(){
    QMap<QString, Qt::PenJoinStyle > map;
    map["MiterJoin"]=Qt::MiterJoin;
    map["BevelJoin"]=Qt::BevelJoin;
    map["RoundJoin"]=Qt::RoundJoin;
    pen.setJoinStyle(map[props.value("PenJoinStyle")]);
}

void Shape::setBrushColor(){
    brush.setColor(QColor(props.value("BrushColor")));
}

void Shape::setBrushStyle(){
    QMap<QString, Qt::BrushStyle > map;
    map["MiterJoin"]=Qt::NoBrush;
    map["SolidPattern"]=Qt::SolidPattern;
    map["Dense1Pattern"]=Qt::Dense1Pattern;
    map["Dense2Pattern"]=Qt::Dense2Pattern;
    map["Dense4Pattern"]=Qt::Dense4Pattern;
    map["Dense5Pattern"]=Qt::Dense5Pattern;
    map["Dense6Pattern"]=Qt::Dense6Pattern;
    map["Dense7Pattern"]=Qt::Dense7Pattern;
    map["HorPattern"]=Qt::HorPattern;
    map["VerPattern"]=Qt::VerPattern;
    map["CrossPattern"]=Qt::CrossPattern;
    map["BDiagPattern"]=Qt::BDiagPattern;
    map["FDiagPattern"]=Qt::FDiagPattern;
    map["DiagCrossPattern"]=Qt::DiagCrossPattern;
    map["LinearGradientPattern"]=Qt::LinearGradientPattern;
    map["ConicalGradientPattern"]=Qt::ConicalGradientPattern;
    map["RadialGradientPattern"]=Qt::RadialGradientPattern;
    map["TexturePattern"]=Qt::TexturePattern;
    brush.setStyle(map[props.value("BrushStyle")]);
}

void Shape::modify(const QString& key, const QString& value){
    props[key]=value;
}


QMap<QString,QString>& Shape::getDictionary (){
    return props;
}
