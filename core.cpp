#include <iostream>
#include <stdlib.h>



//шифровани
#define CES_KEY 3

char * ces(char * data, int lenght, int key){
	for (int i = 0; i < lenght; ++i)
	{
		std::cout << (int)data[i] << "-->";
		data[i] = data[i] + key;
		std::cout << (int)data[i] << std::endl;
	}
	return data;
}

char * ces(char * data, int lenght){
	return ces(data, lenght, CES_KEY);
}

char * unces(char * data, int lenght, int key){
	for (int i = 0; i < lenght; ++i)
	{
		std::cout << (int)data[i] << "-->";
		data[i] = data[i] - key;
		std::cout << (int)data[i] << std::endl;
	}
	return data;
}

char * unces(char * data, int lenght){
	return unces(data, lenght, CES_KEY);
}