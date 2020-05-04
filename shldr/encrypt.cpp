#include <iostream>
#include <stdlib.h>
#include <time.h>

#include <QDate>
#include <QFile>
#include <QMessageBox>
#include <QTime>

#include <fstream>

namespace enc {
//шифрованиe методом xor

void encode(char * data_in, char * data_out, int lenght, char * key, int key_lenght){
    for (int i = 0; i < lenght; ++i)
    {
        data_out[i] = data_in[i] ^ key[i % key_lenght];
    }
}

void ces(char * data, int lenght, int key){
    for (int i = 0; i < lenght; ++i)
    {
        //std::cout << data[i] << "-->";
        data[i] = data[i] + key;
        //std::cout << data[i] << std::endl;
    }
}

void unces(char * data, int lenght, int key){
    for (int i = 0; i < lenght; ++i)
    {
        //std::cout << data[i] << "-->";
        data[i] = data[i] - key;
        //std::cout << data[i] << std::endl;
    }
}

}

void enc_test(){
    char d[16] = "tsun tsun dere";
    char pass[16] = "";

    enc::encode(d, d, 16, pass, 16);
    std::cout << d << std::endl;
    enc::encode(d, d, 16, pass, 16);
    std::cout << d << std::endl;
}
