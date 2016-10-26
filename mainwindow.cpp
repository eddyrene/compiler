#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);
    ui->textEdit->setText("/* \n S'->S \n S-> ID S Integer \n  S->coma  \n*/ \n //cadena: \n (x,(x)) ");/*  */
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::on_pushButton_clicked(){
    ui->textEdit_2->setText(ui->textEdit->toPlainText());

    //-----------------------
    QString qst=ui->textEdit->toPlainText();
    string code= qst.toStdString();
    cout<< code <<"\n"<<endl;
    /* ejecucion */
    _compiler.set_source_code(code);
    _compiler.run();

    cout<<endl;
    //-----------------------

}
