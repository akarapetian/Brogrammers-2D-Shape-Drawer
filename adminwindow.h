#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include <QDialog>
#include "vector.h"
#include "shape.h"

namespace Ui {
class adminWindow;
}

class adminWindow : public QDialog
{
    Q_OBJECT

public:
    explicit adminWindow(QWidget *parent = 0);
    ~adminWindow();

private slots:
    void on_pushButton_clicked();

    void on_readFile_clicked();

private:
    Ui::adminWindow *ui;

    vector<Shape> *shapeVector;
};

#endif // ADMINWINDOW_H
