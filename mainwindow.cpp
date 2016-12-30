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
   // executar();
    on_pushButton_3_clicked(); // Analisis Léxico
    on_pushButton_5_clicked(); // Analisis
}



void MainWindow::on_pushButton_3_clicked(){//lexer
    QString qst=ui->textEdit->toPlainText();
    string code= qst.toStdString();
    _compiler.set_source_code(code);
    _compiler.run_lexer();

    vector<string> v_s= _compiler._lexer.get_buffer_tokens();
    string string_tokens="";
    for(auto i:v_s){
        string_tokens = string_tokens+i+'\n';
    }
    ui->textEdit_2->setText( QString::fromStdString(string_tokens) );
}


void MainWindow::on_pushButton_5_clicked(){//parser
    on_pushButton_3_clicked();
    _compiler.run_parser();
    QImage image("tree.gv.png");
    ui->label_arbol->setPixmap(QPixmap::fromImage( image ));
}


void MainWindow::executar(){
    QString qst=ui->textEdit->toPlainText();
    string code= qst.toStdString();
    cout<< code <<"\n"<<endl;
    /* ejecucion */
    _compiler.set_source_code(code);
    _compiler.run();
}
