/**
 * @file continuouslaw.cpp
 * @author AiglonDore
 * @brief Implements {@link continuouslaw.h}.
 * @version 0.1
 * @date 2022-07-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "../headers/continuouslaw.h"
#include "../headers/utils.h"

double ContinuousLaw::proba(long long int X)
{
    return proba(double(X));
}

double ContinuousLaw::proba(double X)
{
    return repartition(X);
}

double ContinuousLaw::proba(double lowerBound, double upperBound)
{
    return proba(upperBound) - proba(lowerBound);
}

double ContinuousLaw::proba(long long int lowerBound, long long int upperBound)
{
    return proba(upperBound) - proba(lowerBound);
}

double ContinuousLaw::density(double X)
{
    return densityFunction(X);
}

double ContinuousLaw::repartition(double X)
{
    return Utils::Operators::integral(false,densityFunction,X);
}