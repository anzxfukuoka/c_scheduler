#include <iostream>
#include <string>
#include <cstring>
/*#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <vector>
#include <fstream>
*/

#include "core.h"
#include <time.h>

void debug(int argc, char const *argv[])
{
	char test[16] = "qwerty";
	ces(test, strlen(test));
	std::cout << test << std::endl;
	unces(test, strlen(test));
	std::cout << test << std::endl;

}

