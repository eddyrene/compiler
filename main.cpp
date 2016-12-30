#include "mainwindow.h"
#include <QApplication>
#include <istream>
#include "compiler.h"
using namespace std;


int main(int argc, char *argv[]){
    //---interfaz
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
