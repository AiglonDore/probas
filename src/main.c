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
#include <stdlib.h>
#include <string.h>

/**
 * @brief Displays help about all available functions.
 * 
 */
void showHelp()
{
	printf("Usage: probas");
	printf("Calculus: calc\n");
	printf("bern p x: probability of x using a Bernoulli law\n");
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
	if (!strcmp(argv[1],"--version") || !strcmp(argv[1],"version") || !strcmp(argv[1],"-v"))
	{
		printf("Version : %s\n",VERSION);
		return 0;
	}

	return 0;
}
