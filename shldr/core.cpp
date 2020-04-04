#include <iostream>
#include <stdlib.h>
#include <time.h>

#include <QDate>
#include <QTime>

#include <fstream>

/*#define TASKSFILE "C:\\Users\\Anzx\\Desktop\\CR\\data.tasks"

struct Task{
    char name[16];
    char disc[240]; //описание
    bool done;
    bool expired;
    time_t date;
};


bool save(Task * task){
    FILE * f;

    if ((f = fopen(TASKSFILE, "ab")) != NULL){

        fwrite(task, sizeof(Task), 1, f);
    }
    else
    {
        perror("ошибка записи");
        fclose(f);
        return false;
    }

    fclose(f);
    return true;
}

void getall(){//?

}

bool read(Task * task){//?
    FILE * f;

    if ((f = fopen(TASKSFILE, "rb")) != NULL){

        //fwrite(task, sizeof(Task), 1, f);
        fread((char *)task, sizeof(Task), 1, f);
    }
    else
    {
        perror("ошибка записи");
        fclose(f);
        return false;
    }

    fclose(f);
    return true;
}

*/

//debug trash
void time_now(){

    std::cout << "time_t: " << sizeof(time_t) << std::endl;
    std::cout << "Qdate " << sizeof(QDate) << std::endl;
    std::cout << "Qtime " << sizeof(QTime) << std::endl;
    std::cout << "QDateTime " << sizeof(QDateTime) << std::endl;

    time_t rawtime;
    struct tm * timeinfo;

    time (&rawtime); //sec
    std::cout << rawtime << std::endl;
    std::cout << localtime(&rawtime) << std::endl;

    struct tm * t1;
    struct tm * t2;

    t1 = localtime(&rawtime);
    t2 = localtime(&rawtime);

    t1->tm_year = 2010;

    char buffer [80];
    strftime (buffer, 80 , "Now it's %c", t1);

    std::cout << buffer << std::endl;

    time_t sec = mktime (t2);

}

//шифрованиe
#define CES_KEY 3

char * ces(char * data, int lenght, int key){
    for (int i = 0; i < lenght; ++i)
    {
        std::cout << data[i] << "-->";
        data[i] = data[i] + key;
        std::cout << data[i] << std::endl;
    }
    return data;
}

char * ces(char * data, int lenght){
    return ces(data, lenght, CES_KEY);
}

char * unces(char * data, int lenght, int key){
    for (int i = 0; i < lenght; ++i)
    {
        std::cout << data[i] << "-->";
        data[i] = data[i] - key;
        std::cout << data[i] << std::endl;
    }
    return data;
}

char * unces(char * data, int lenght){
    return unces(data, lenght, CES_KEY);
}
