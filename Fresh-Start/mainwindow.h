#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "renderarea.h"
#include "vector.h"

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

    void on_actionPerimeters_triggered();

    void on_actionAreas_triggered();

    void on_actionOur_Information_triggered();

    void on_returnButton_clicked();

    void on_returnButton_2_clicked();

    void on_horizSpinBox_valueChanged(int arg1);

    void on_vertSpinBox_valueChanged(int arg1);

private:
    Ui::MainWindow *ui;

    renderArea *renderWindow;

    QString loginType;

};

#endif // MAINWINDOW_H
