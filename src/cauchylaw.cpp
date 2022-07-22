/**
 * @file cauchylaw.cpp
 * @author AiglonDore
 * @brief Implements {@link cauchylaw.h}.
 * @version 0.1
 * @date 2022-07-22
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "../headers/cauchylaw.h"
#include "../headers/utils.h"

CauchyLaw::CauchyLaw() : a(1)
{
    densityFunction = [](double t){
        if (t <= 0) return 0.0;
        return 1 / 3.14159265359 * 1 / (t * t);
    };
}

CauchyLaw::CauchyLaw(double a) : a(a)
{
    if (a <= 0)
    {
        throw Exception(Cauchy,"The parameter of a Cauchy Law is always strictly positive.");
    }
    densityFunction =  [a](double t){
        if (t <= 0) return 0.0;
        return a / 3.14159265359 * 1 / std::pow(t - a,2);
    };
}

CauchyLaw::~CauchyLaw()
{
}

double CauchyLaw::repartition(double X)
{
    if (X <= 0) return 0.0;
    return Utils::Operators::integral(densityFunction,0,X);
}

double CauchyLaw::stdDev()
{
    throw Exception(Cauchy,"Cauchy Law doesn't have a variance so standard deviation is not defined.");
}

double CauchyLaw::expectancy()
{
    throw Exception(Cauchy,"Cauchy Law cannot be integrated on the positive real numbers so it has no finished expectancy.");
}

double CauchyLaw::variance()
{
    throw Exception(Cauchy,"Cauchy Law cannot be integrated on the positive real numbers so it has no finished variance.");
}