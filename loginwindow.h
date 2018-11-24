#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QWidget>

#include "adminwindow.h"
#include "userwindow.h"

//this class is the login window prompt, allows the user to login as user or admin

namespace Ui {
class loginWindow;
}

class loginWindow : public QWidget
{
    Q_OBJECT

public:
    explicit loginWindow(QWidget *parent = 0);
    ~loginWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::loginWindow *ui;
    adminWindow *adminWin;
    userWindow *userWin;
};

#endif // LOGINWINDOW_H
