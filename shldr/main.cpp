#include "mainwindow.h"

#include <QApplication>

//#include "core.cpp"
//#include "storage.cpp"

#include <time.h>
#include <QDate>
#include <QTime>

int main(int argc, char *argv[])
{
    //storage_test();
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
