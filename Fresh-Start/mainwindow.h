#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "renderarea.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionLogin_triggered();

    void on_loginButton_clicked();

    void on_addShapeButton_clicked();

private:
    Ui::MainWindow *ui;

    renderArea *renderWindow;
};

#endif // MAINWINDOW_H
