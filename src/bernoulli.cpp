/**
 * @file bernoulli.cpp
 * @author AiglonDore
 * @brief Implements {@link bernoulli.h}.
 * @version 0.1
 * @date 2022-06-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <cmath>

#include "../headers/bernoulli.h"

BernoulliLaw::BernoulliLaw() : p(0.5)
{
}

BernoulliLaw::BernoulliLaw(double p) : p(p)
{
    if (p < 0 || p > 1)
    {
        throw Exception(ExceptionType::Bernoulli,"Parameter must be bewteen 0 and 1.");
    }
}

BernoulliLaw::~BernoulliLaw()
{
}

double BernoulliLaw::proba(long long int X)
{
    if (X != 0 && X != 1)
    {
        return 0.0;
    }
    return X?p:1-p;
}

double BernoulliLaw::expectancy()
{
    return p;
}

double BernoulliLaw::variance()
{
    return p * (1 - p);
}

double BernoulliLaw::repartition(double X)
{
    if (X < 0) return 0;
    if (X < 1) return 1 - p;
    else return 1;
}