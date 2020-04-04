/*
Файл модуля работы с файлами
этот модул предоставляет две функции работы с файлами:

void save(QVector<Task> tasks) - сохранить массив с записями в файл
void save(Task tasks) - сохранить запись в файл
QVector<Task> read() - считать массив с записями из файла

при ошибке записи save() бросает исключение WRITEEXCEPTION
при ошибке чтения read() бросает исключения FILEEXCEPTION и NOFILEEXCEPTION
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

#include <fstream>
#include <cstring>

#include <QVector>

namespace ts { //task storage

//debug
#define TASKSFILE "C:\\Users\\Anzx\\Desktop\\CR\\data.tasks"

FILE * tasksfile;

int currpos = 0;

struct Task{
    char name[16];
    char disc[240]; //описание
    bool done;
    bool expired;
    time_t date;
};

//ошибки

#define NOFILEEXCEPTION "в файле нет записей"
#define FILEEXCEPTION "ошибка чтения файла"
#define WRITEEXCEPTION "ошибка записи"

void save(Task * task){
    FILE * f;

    if ((f = fopen(TASKSFILE, "ab")) != NULL){

        fwrite(task, sizeof(Task), 1, f);
    }
    else
    {
        perror("ошибка записи");
        fclose(f);
        throw WRITEEXCEPTION;
    }

    fclose(f);
}

bool save()

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

    if ((f = fopen(TASKSFILE, "rb")) != NULL){
        fseek(f, 0, SEEK_END);
        long lenght = ftell(f);
        int count = lenght/sizeof(Task);

        if(count == 0){
            perror("в файле нет записей");
            throw NOFILEEXCEPTION;
        }

        Task * next = new Task;
        int id;
        while ((id = readone(f, next)) != -1) {
           tasks.append(*next);
        }


    }
    else
    {
        perror("ошибка xntybz");
        fclose(f);
        throw FILEEXCEPTION;
    }

    fclose(f);
    return tasks;

}


}

