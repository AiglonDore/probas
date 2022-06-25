/**
 * @file main.c
 * @author AiglonDore
 * @brief Main file.
 * @version 0.1
 * @date 2022-06-25
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#define VERSION "0.1"

#include <stdio.h>

/**
 * @brief Displays help about all available functions.
 * 
 */
void showHelp()
{

}

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

	return 0;
}
