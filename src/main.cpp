/**
 * @file main.cpp
 * @author AiglonDore
 * @brief Main file.
 * @version 0.1
 * @date 2022-06-25
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief Macro that holds the version of the program.
 */
#define VERSION "0.1"

#include <iostream>
#include <string>
#include <cstring> //Provides strcmp.

using namespace std;

#include "../headers/help.h"
#include "../headers/law.h"

/**
 * @brief Main function.
 * 
 * @param argc Number of arguments.
 * @param argv List of arguments.
 * @return int Error code.
 */
int main(int argc, char *argv[])
{
	printf("-----Probabilty tools and calculation v%s-----\n",VERSION);

	if (argc == 1)
	{
		showHelp();
		return 0;
	}
	if (!strcmp(argv[1],"--version") || !strcmp(argv[1],"version") || !strcmp(argv[1],"-v"))
	{
		printf("Version : %s, made by AiglonDore and HoudaAib with love!\n",VERSION);
		return 0;
	}

	return 0;
}
