/**
 * @file bernoulli.h
 * @author AiglonDore
 * @brief Provides functions relted to the Bernulli law.
 * @version 0.1
 * @date 2022-06-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef BERNOULLI_H
#define BERNOULLI_H

/**
 * @brief Alias to distinguish the Bernoulli's law parameter.
 * @warning All functions in this file will assume that this parameter is in ]0;1[.
 * 
 */
typedef double Bernoulli;

/**
 * @brief Returns the probability P(X=x).
 * 
 * @param x Value assumed by the law. If x!=0 and x!=1, then 0 in returned.
 * @param p 
 * @return double 
 */
double probability(unsigned int x, Bernoulli p);




#endif //BERNOULLI_H