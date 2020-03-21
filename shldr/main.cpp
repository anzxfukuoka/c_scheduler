#include "mainwindow.h"

#include <QApplication>

#include "core.cpp"

#include <time.h>
#include <QDate>
#include <QTime>

int main(int argc, char *argv[])
{
    //char test[] = "rtyuio";
    //ces(test, strlen(test));

    //time_now();

    Task * newt = new Task;

    strcpy(newt->name, "feed cat");
    strcpy(newt->disc, "nya~");
    newt->done = false;
    newt->expired = true;

    time (&newt->date);

    printf("name: %s \ndisc: %s\n done: %d\n expired: %d\ntime: %s", newt->name, newt->disc, newt->done, newt->expired, asctime(localtime(&(newt->date))));

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
