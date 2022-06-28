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

double DiscreteLaw::proba(double lowerBound, double upperBound)
{
    long long int tmp1 = lowerBound;
    long long int tmp2 = upperBound;
    return this->proba(tmp1,tmp2);
}

double DiscreteLaw::proba(long long int lowerBound, long long int upperBound)
{
    double s = 0.0;
    for (long long int i = lowerBound; i <= upperBound; i++)
    {
        s += this->proba(i);
    }
    return s;
}