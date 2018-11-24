#include "adminwindow.h"
#include "ui_adminwindow.h"

adminWindow::adminWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adminWindow)
{
    ui->setupUi(this);

    //call parser
    //shapeVector =
}

adminWindow::~adminWindow()
{
    delete ui;
}


void adminWindow::on_readFile_clicked()
{
    //fill vector
}
