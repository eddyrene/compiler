#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QImage>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);
    ui->textEdit->setText("int a;");/*  */
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::on_pushButton_clicked(){




            // ui->label_arbol->setPixmap(QPixmap::fromImage( image ));

    //ui->textEdit_2->setText(ui->textEdit->toPlainText());
    //-----------------------
    QString qst=ui->textEdit->toPlainText();
    string code= qst.toStdString();
    cout<< code <<"\n"<<endl;
    /* ejecucion */
    _compiler.set_source_code(code);
    _compiler.run();

    QImage image("tree.gv.png");
    if( image.isNull() )
    {
        cout<<"error , no se pudo cargar la imagen"<<endl;
    }
    ui->label_arbol->setPixmap(QPixmap::fromImage( image ));


    cout<<endl;
    //-----------------------

}


