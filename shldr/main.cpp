#include "mainwindow.h"

#include <QApplication>

//#include "core.cpp"
#include "storage.cpp"

#include <time.h>
#include <QDate>
#include <QTime>

int main(int argc, char *argv[])
{
    //char test[] = "rtyuio";
    //ces(test, strlen(test));

    //time_now();

    ts::Task * newt = new ts::Task;

    strcpy(newt->name, "tea party");
    strcpy(newt->disc, "uwu");
    newt->done = false;
    newt->expired = false;

    time(&newt->date);

    //printf("name: %s \ndisc: %s\n done: %d\n expired: %d\ntime: %s", newt->name, newt->disc, newt->done, newt->expired, asctime(localtime(&(newt->date))));

    //ts::save(newt);
    //if(read()){
    //    std::cout << tasks[1].date;
    //}

    try {
        QVector<ts::Task> tasks = ts::read();
        //std::cout << sizeof (ts::Task) << std::endl;
        //tasks.remove(2);
        for(int i = 0; i < tasks.length(); i++)
            printf("name: %s \tdisc: %s\t done: %d\t expired: %d\ttime: %s", tasks[i].name, tasks[i].disc, tasks[i].done, tasks[i].expired, asctime(localtime(&(tasks[i].date))));
        ts::save(tasks);
    } catch (char* somthing) {
        std::cout << somthing << std::endl;
    }


    //while(read(tt)){
    //    printf("name: %s \ndisc: %s\n done: %d\n expired: %d\ntime: %s", tt->name, tt->disc, tt->done, tt->expired, asctime(localtime(&(tt->date))));
    //}

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
