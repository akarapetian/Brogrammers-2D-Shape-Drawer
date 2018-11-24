#include "adminwindow.h"
#include "ui_adminwindow.h"

adminWindow::adminWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adminWindow)
{
    ui->setupUi(this);

    QPoint p1;
    p1.rx() = 10;
    p1.ry() = 10;

    QPoint p2;
    p2.rx() = 100;
    p2.ry() = 100;

    //need to figure out the correct device and this should work pretty good :)
    //and then need to figure out parser and we gucci
    Shape* shapePtr = new Line("-1", Shape::shapeType::ellipse, this, p1, p2);

   shapeVector.push_back(shapePtr);

}

adminWindow::~adminWindow()
{
    delete ui;
}

void adminWindow::paintEvent(QPaintEvent *event)
{

   shapeVector[0]->draw();
}


void adminWindow::on_readFile_clicked()
{

}
