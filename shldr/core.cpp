#include <iostream>
#include <stdlib.h>
#include <time.h>

#include <QDate>
#include <QTime>

#include <fstream>


//namespase ts


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
