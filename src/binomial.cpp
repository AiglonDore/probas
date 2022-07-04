/**
 * @file binomial.cpp
 * @author AiglonDore
 * @brief Implements {@link binomial.h}.
 * @version 0.1
 * @date 2022-06-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "../headers/binomial.h"
#include "../headers/utils.h"

#include <cmath>

using namespace std;

BinomialLaw::BinomialLaw() : BernoulliLaw(), n(1)
{
}

BinomialLaw::BinomialLaw(double p) : BernoulliLaw(p), n(1)
{
}

BinomialLaw::BinomialLaw(long long int n, double p) : BernoulliLaw(p), n(n)
{
    if (n < 0) throw -3;
}

BinomialLaw::~BinomialLaw()
{
}

double BinomialLaw::proba(long long int X)
{
    if (X < 0 || X > n)
    {
        throw -2;
    }
    
    return Utils::nCr(n,X) * pow(p,X) * pow(1-p,n-X);
}

double BinomialLaw::expectancy()
{
    return n * p;
}

double BinomialLaw::variance()
{
    return n * p * (1 - p);
}