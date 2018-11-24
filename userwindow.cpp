#include "userwindow.h"
#include "ui_userwindow.h"

userWindow::userWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::userWindow)
{
    ui->setupUi(this);
}

userWindow::~userWindow()
{
    delete ui;
}
