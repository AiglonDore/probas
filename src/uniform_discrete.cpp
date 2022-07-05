/**
 * @file uniform_discrete.cpp
 * @author AiglonDore
 * @brief Implements {@link uniform_discrete.h}.
 * @version 0.1
 * @date 2022-06-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "../headers/uniform_discrete.h"

UniformDiscreteLaw::UniformDiscreteLaw() : lowerBound(0), upperBound(1), n(0)
{
    n = upperBound - lowerBound + 1;
}

UniformDiscreteLaw::UniformDiscreteLaw(long long int upperBound) : lowerBound(0), upperBound(upperBound), n(0)
{
    n = upperBound - lowerBound + 1;
    if (n <= 0)
    {
        throw 1;
    }
}

UniformDiscreteLaw::UniformDiscreteLaw(long long int lowerBound, long long int upperBound) : lowerBound(lowerBound), upperBound(upperBound), n(0)
{
    n = upperBound - lowerBound + 1;
    if (n <= 0)
    {
        throw 1;
    }
}

UniformDiscreteLaw::~UniformDiscreteLaw()
{
}

double UniformDiscreteLaw::proba(long long int X)
{
    if (X < lowerBound || X > upperBound)
    {
        return 0;
    }
    return 1. / n;
}

double UniformDiscreteLaw::expectancy()
{
    return (upperBound + lowerBound) / 2.;
}

double UniformDiscreteLaw::variance()
{
    return (n * n - 1.) / 12;
}

double UniformDiscreteLaw::repartition(double X)
{
    if (X < lowerBound) return 0;
    if (X <= upperBound) return (std::floor(X) - lowerBound + 1) / n;
    return 1;
}