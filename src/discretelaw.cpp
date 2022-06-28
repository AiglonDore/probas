/**
 * @file discretelaw.cpp
 * @author AiglonDore
 * @brief Implements {@link discretelaw.h}.
 * @version 0.1
 * @date 2022-06-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "../headers/discretelaw.h"

double DiscreteLaw::proba(double X)
{
    long long int tmp = X;
    return proba(tmp);
}