#include "mainwindow.h"
#include <stdlib.h>
#include <iostream>
#include <QApplication>

int main(int argc, char *argv[])
{
    //storage_test();
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
