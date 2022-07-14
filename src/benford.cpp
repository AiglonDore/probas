/**
 * @file benford.cpp
 * @author AiglonDore
 * @brief Implements {@link benford.h}.
 * @version 0.1
 * @date 2022-07-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "../headers/benford.h"
#include <cmath>

using namespace std;

BenfordLaw::BenfordLaw() : DiscreteLaw(), base(10)
{
}

BenfordLaw::BenfordLaw(unsigned long long int base) : DiscreteLaw(), base(base)
{
    if (base == 0 || base  == 1)
    {
        throw Exception(ExceptionType::Benford,"Base cannot be 0 or 1, or be negative.");
    }
}

BenfordLaw::~BenfordLaw()
{
}

double BenfordLaw::proba(long long int X)
{
    if (X < 1) return 0.0;

    unsigned long long int Y = abs(X);

    if (Y > base) return 0.0;

    if (base == 10) return log10(Y + 1) - log10(Y);

    return 1 / log(base) * (log(Y + 1) - log(Y));
}

double BenfordLaw::expectancy()
{
    double p = 0.0;
    for (size_t i = 1; i < base; i++)
    {
        p += proba(i) * i;
    }
    return p;
}

double BenfordLaw::variance()
{
    double exp2 = pow(expectancy(),2);

    double v = 0;

    for (size_t i = 1; i < base; i++)
    {
        v += i * i * proba(i);
    }

    return v - exp2;
}