/**
 * @file poisson.cpp
 * @author AiglonDore
 * @brief Implements {@link poisson.h}.
 * @version 0.1
 * @date 2022-07-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "../headers/poisson.h"

PoissonLaw::PoissonLaw() : DiscreteLaw(), lambda(1)
{
}

PoissonLaw::PoissonLaw(double lambda) : DiscreteLaw(), lambda(lambda)
{
    if (lambda < 0)
    {
        throw Exception(ExceptionType::Poisson,"Parameter cannot be negative.");
    }
}

PoissonLaw::~PoissonLaw()
{
}

double PoissonLaw::proba(long long int X)
{
    if (X < 0) return 0.0;
    return std::pow(lambda,X) / Utils::fact(X) * std::exp(-lambda);
}

double PoissonLaw::expectancy()
{
    return lambda;
}

double PoissonLaw::variance()
{
    return lambda;
}

double PoissonLaw::repartition(double X)
{
    if (X < 0)
    {
        return 0;
    }
    else
    {
        long long int tmp = X;
        return Utils::Gamma(tmp + 1,lambda) / Utils::fact(tmp);
    }
}

PoissonLaw& PoissonLaw::operator+=(const PoissonLaw& other)
{
    lambda += other.getLambda();
    return *this;
}

PoissonLaw operator+(const PoissonLaw& first, const PoissonLaw& second)
{
    PoissonLaw copy(first);
    return copy += second;
}