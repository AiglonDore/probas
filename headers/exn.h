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
    /**
     * @brief Construct a new Exception object. Its type will be Calculus and its message will be empty.
     * 
     */
    Exception();
    /**
     * @brief Construct a new Exception object.
     * 
     * @param type Type of the exception.
     * @param message Message to be displayed.
     */
    Exception(ExceptionType type, const std::string& message = "");
    /**
     * @brief Destroy the Exception object.
     * 
     */
    virtual ~Exception();
    /**
     * @brief Get the Message object.
     * 
     * @return const std::string& Message as a reference.
     */
    const std::string& getMessage() const { return message; };

    void setMessage(const std::string& message) { this->message = message; };
    /**
     * @brief Get the Type object.
     * 
     * @return ExceptionType Type of the exception.
     */
    const ExceptionType getType() const { return type; };
};


#endif //EXN_H