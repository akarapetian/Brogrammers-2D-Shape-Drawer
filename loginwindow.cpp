#include "loginwindow.h"
#include "ui_loginwindow.h"
#include <QMessageBox>

loginWindow::loginWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::loginWindow)
{
    ui->setupUi(this);
}

loginWindow::~loginWindow()
{
    delete ui;
}

void loginWindow::on_pushButton_clicked()
{
    QString username = ui->lineEdit->text();
    QString password = ui->lineEdit_2->text();

    hide();

    if(username == "admin" && password == "admin")
    {
        //open admin dialog window
        adminWin = new adminWindow(this);
        adminWin -> show();
    }
    else if(username == "user" && password == "user")
    {
        //open user dialog window
        userWin = new userWindow(this);
        userWin -> show();
    }
    else
    {
        QMessageBox::warning(this, "Login", "Username and password is not correct!");
    }
}
