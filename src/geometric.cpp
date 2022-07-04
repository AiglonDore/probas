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

HyperGeometricLaw::HyperGeometricLaw() : GeometricLaw(), n(0), A(1)
{
}

HyperGeometricLaw::HyperGeometricLaw(long long int n,double p, long long int A) : GeometricLaw(p), n(n), A(A)
{
}

HyperGeometricLaw::~HyperGeometricLaw()
{
}