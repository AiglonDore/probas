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

#include <cmath>

using namespace std;

/**
 * @brief Computes n!.
 * 
 * @param n Value.
 * @return int n!.
 */
long long int fact(long long int n)
{
    long long int p = 1;
    for (long long int i = 1; i <= n; i++)
    {
        p *= i;
    }
    return p;
}

/**
 * @brief Returns the binomial coefficient.
 * 
 * @param n Number of items.
 * @param k Number of slices.
 * @return int Binomial coefficient.
 */
long long int nCr(long long int n, long long int k)
{
    if (n < 0 || k < 0 || k > n)
    {
        return 0;
    }
    return fact(n) / (fact(k) * fact(n - k));
}

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
    
    return nCr(n,X) * pow(p,X) * pow(1-p,n-X);
}

double BinomialLaw::expectancy()
{
    return n * p;
}

double BinomialLaw::variance()
{
    return n * p * (1 - p);
}