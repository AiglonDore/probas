/**
 * @file exn.h
 * @author AiglonDore
 * @brief Holds exception classes.
 * @version 0.1
 * @date 2022-07-14
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef EXN_H
#define EXN_H

#include <string>

/**
 * @brief Provides a list of the type of exceptions.
 * 
 */
enum ExceptionType {Benford, Bernoulli, Binomial, Geometric, Poisson, UniformDiscrete,Calculus};

/**
 * @brief The Exception class provides exceptions for the other classes.
 * 
 */
class Exception
{
private:
    ExceptionType type;
    std::string message;
public:
    Exception();
    Exception(ExceptionType type, const std::string& message);
    Exception(ExceptionType type, std::string&& message);
    virtual ~Exception();
};


#endif //EXN_H