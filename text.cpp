/*
#include "text.h"
#include <QFont>
#include <QPen>
#include <QMap>
#include <QStringList>
#include <QPainter>

Text::Text(std::string id, shapeType shape, QPaintDevice* devicee)
{
}

void Text::draw()
{
    getQPainter().begin(getQDevice());
    setStyles();
    QStringList words = props["ShapeDimensions"].split(", ");
    drawIdentifier(words[0].toInt(), words[1].toInt());
    getQPainter().drawText(words[0].toInt(), words[1].toInt(), words[2].toInt(), words[3].toInt(), textAlignment(props["TextAlignment"]), textString);
    getQPainter().end();
}

void Text::setStyles(){
    QFont font = QFont( props["TextFontFamily"], props["TextPointSize"].toInt(), getWeight(props["TextFontWeight"]), false);
    getQPainter().setFont(font);
    QColor color = QColor(props["TextColor"]);

    QPen pen(color);
    QMap<QString, Qt::PenCapStyle> map;
    map["SquareCap"] = Qt::SquareCap;
    map["FlatCap"] = Qt::FlatCap;
    map["RoundCap"] = Qt::RoundCap;
    pen.setCapStyle(map[props["TextFontStyle"]]);
    getQPainter().setPen(pen);
}



int Text::textAlignment(const QString &align){
    QMap<QString, int> map;
    map["AlignLeft"] = Qt::AlignLeft;
    map["AlignRight"] = Qt::AlignRight;
    map["AlignHCenter"] = Qt::AlignHCenter;
    map["AlignJustify"] = Qt::AlignJustify;
    map["AlignTop"] = Qt::AlignTop;
    map["AlignBottom"] = Qt::AlignBottom;
    map["AlignVCenter"] = Qt::AlignVCenter;
    map["AlignCenter"] = Qt::AlignCenter;
    map["TextSingleLine"] = Qt::TextSingleLine;
    map["TextExpandTabs"] = Qt::TextExpandTabs;
    map["TextShowMnemonic"] = Qt::TextShowMnemonic;
    map["TextWordWrap"] = Qt::TextWordWrap;
    return map[align];
}

int Text::getWeight(const QString &weight){
    QMap<QString, QFont::Weight> map;
    map["Light"] = QFont::Light;
    map["Normal"] = QFont::Normal;
    map["DemiBold"] = QFont::DemiBold;
    map["Bold"] = QFont::Bold;
    map["Black"] = QFont::Black;
    return map[weight];
}

int Text::getFontStyle(const QString &weight){
    QMap<QString, Qt::PenCapStyle> map;
    map["FlatCap"] = Qt::FlatCap;
    map["SquareCap"] = Qt::SquareCap;
    map["RoundCap"] = Qt::RoundCap;
    return map[weight];
}


double Text::perimeter(){
    return -1;
}

double Text::area(){
    return -1;
}

void Text::move(const int translateX, const int translateY){
    return;
}



*/
