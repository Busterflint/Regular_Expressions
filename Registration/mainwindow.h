#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "regnumbers.h"

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
    void addRecord();
    void deleteRecord();

private:
    Ui::MainWindow *ui;
    RegNumbers regNumbers;
};

#endif // MAINWINDOW_H
