#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>
#include "compiler.h"
using namespace std;


namespace Ui {
    class MainWindow;
}

    class MainWindow : public QMainWindow{
        Q_OBJECT

    private:
        Ui::MainWindow *ui;
        compiler _compiler;


    public:
        explicit MainWindow(QWidget *parent = 0);
        ~MainWindow();

    private slots:
        void on_pushButton_clicked();

    };

#endif // MAINWINDOW_H
