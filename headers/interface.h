/**
 * @file interface.h
 * @author AiglonDore
 * @brief Provides functions to ask for values.
 * @version 0.1
 * @date 2022-06-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef INTERFACE_H
#define INTERFACE_H

/**
 * @brief Executes the specified command.
 * 
 * @param argc Number of arguments.
 * @param argv Vector of arguments.
 * @warning The first argument is the name of the program. It should be avoided.
 */
void execute(int argc, char *argv[]);

#endif //INTERFACE_H