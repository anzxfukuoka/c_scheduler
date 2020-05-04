/*
storage.cpp
Файл модуля работы с файлами
этот модул предоставляет две функции работы с файлами:

void setpath(std::string p) - сеттер для путя к файлу
void save(QVector<Task> tasks) - сохранить массив с записями в файл
void save(Task * task) - сохранить запись в файл
QVector<Task> read() - считать массив с записями из файла

при ошибке записи save() бросает исключение WRITEEXCEPTION
при ошибке чтения read() бросает исключения FILEEXCEPTION
при использованнии данных фунуций их следует поместить в блок try catch

подобнвй метот огранизации работы этого модуля был смотивированн простотой и скоростью реализации.
при работе с фалом записи "по блочно", считывая и изменяя или удаляя по одной, записи можно бы было сэкономить ресурсы компьютера,
но, так как один обьект записи Task весит 264 байта, то даже если в файле будет хранится 1000 записей, то
при кадом запуске программы будет тратится +264 килобайт оперативной прмяти компютера, что нкизмеримо мало для <4 гигабайт в
современных пк, для того, чтобы логически услоднять код.
*/

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>

#include <fstream>
#include <cstring>

#include <QVector>

#include "encrypt.cpp"

namespace ts { //task storage

const int NAME_LEN = 16;
const int DISC_LEN = 240;
const int KEY_LEN = 64;

//путь к файлу с запясями.

char *cuser = std::getenv("USERNAME");
std::string user(cuser);

std::string path = "C:/Users/" + user + "/shelduedata.tasks";

int currpos = 0;

char key[KEY_LEN] = "";

struct Task{
    char name[NAME_LEN];
    char disc[DISC_LEN]; //описание
    bool done;
    bool expired;
    time_t date;
};

//ошибки
#define NOFILEEXCEPTION "в файле нет записей"
#define FILEEXCEPTION "ошибка чтения файла"
#define WRITEEXCEPTION "ошибка записи"

void setpath(std::string p){
    path = p;
}

void setkey(char * k){
    strcpy(key, k);
}

void save(QVector<Task> tasks){

    FILE * f;

    Task task;

    if ((f = fopen(path.c_str(), "wb")) != NULL){

        for(int i = 0; i < tasks.length(); i++){
            task = tasks[i];
            fwrite(&task, sizeof(Task), 1, f);
        }
    }
    else
    {
        perror(WRITEEXCEPTION);
        fclose(f);
        throw WRITEEXCEPTION;
    }

    fclose(f);
}

int readone(FILE * fs, Task * next){

    fseek(fs, 0, SEEK_END);
    long lenght = ftell(fs);
    if(lenght == 0){
        //файл пустой
        perror("файл пустой");
        currpos = 0;
        return -1;
    }
    if(lenght <= currpos * sizeof(Task)){
        //дошел до конца
        currpos = 0;
        return -1;
    }

    fseek(fs, currpos * sizeof(Task), SEEK_SET);
    fread(next, sizeof(Task), 1, fs);
    //cout << "считан " << nextpos << endl;
    currpos++;
    return currpos;
}

QVector<Task> read(){
    FILE * f;
    QVector<Task> tasks;

    if ((f = fopen(path.c_str(), "rb")) != NULL){
        fseek(f, 0, SEEK_END);
        long lenght = ftell(f);
        int count = lenght/sizeof(Task);

        if(count != 0){
            //файл не пустой
            Task * next = new Task;
            int id;
            while ((id = readone(f, next)) != -1) {
               tasks.append(*next);
            }
        }
    }
    else
    {
        //файла не существует
        if((f = fopen(path.c_str(), "w")) == NULL){
            //файл не удалось создать
            perror(FILEEXCEPTION);
            fclose(f);
            throw FILEEXCEPTION;
        }
    }

    fclose(f);
    return tasks;

}

//ту стд::стринг
std::string to_string(Task t){
    return "name: " + std::string(t.name) +
           //"\ndisc: " + std::string(t.disc) +
           "\n done: " + std::to_string(t.done) +
           "\n expired: " + std::to_string(t.expired) +
           "\ntime: " + std::string(asctime(localtime(&(t.date))));
}

}

//тест модуля
void storage_test(){
    ts::Task * newt = new ts::Task;

    strcpy(newt->name, "бинт");
    strcpy(newt->disc, "ь.");
    newt->done = false;
    newt->expired = false;

    time(&newt->date);

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
}
