/**
 * @file geometric.cpp
 * @author AiglonDore
 * @brief Implements {@link geometric.h}.
 * @version 0.1
 * @date 2022-07-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "../headers/geometric.h"

GeometricLaw::GeometricLaw() : BernoulliLaw()
{
}

GeometricLaw::GeometricLaw(double p) : BernoulliLaw(p)
{
}

GeometricLaw::~GeometricLaw()
{
}

double GeometricLaw::proba(long long int X)
{
    if (X <= 0)
    {
        throw -1;
    }
    return pow(1-p,X-1) * p;
}

double GeometricLaw::expectancy()
{
    return 1 / p;
}

double GeometricLaw::variance()
{
    return (1 - p) / (p * p);
}