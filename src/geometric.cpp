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
#include <cmath>

#include "../headers/geometric.h"
#include "../headers/utils.h"

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

double GeometricLaw::repartition(double X)
{
    return 1 - std::pow(1 - p,std::floor(X));
}

HyperGeometricLaw::HyperGeometricLaw() : GeometricLaw(), n(0), A(1)
{
}

HyperGeometricLaw::HyperGeometricLaw(long long int n,double p, long long int A) : GeometricLaw(p), n(n), A(A)
{
}

HyperGeometricLaw::~HyperGeometricLaw()
{
}

double HyperGeometricLaw::proba(long long int X)
{
    if (X < std::max(0.,n-(1 - p) * A) || X > std::min(p * A,double(n)))
    {
        return 0.0;
    }
    return double(Utils::nCr(int(p * A),X)) * Utils::nCr(int((1 - p) * A),n - X) /  Utils::nCr(A,n);
}

double HyperGeometricLaw::expectancy()
{
    return n * p;
}

double HyperGeometricLaw::variance()
{
    return n * p * (1 - p) * (A - n) / (A - 1);
}

double HyperGeometricLaw::repartition(double X)
{
    return DiscreteLaw::repartition(X);
}