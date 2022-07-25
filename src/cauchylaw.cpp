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

CauchyLaw::CauchyLaw() : a(1), x0(0)
{
    densityFunction = [](double t){
        return 1 / 3.14159265359 * 1 / (t * t + 1);
    };
}

CauchyLaw::CauchyLaw(double a) : a(a)
{
    x0 = 0.0;
    if (a <= 0)
    {
        throw Exception(Cauchy,"The parameter of a Cauchy Law is always strictly positive.");
    }
    densityFunction =  [a](double t){
        return a / 3.14159265359 * 1 / (t * t + a * a);
    };
}

CauchyLaw::CauchyLaw(double x,double a0) : a(a0), x0(x0)
{
    densityFunction = [a0,x](double t){
        return a0 / 3.14159265359 * 1 / (std::pow(t - x,2) + a0 * a0);
    };
}

CauchyLaw::~CauchyLaw()
{
}

double CauchyLaw::repartition(double X)
{
    return 1 / 3.14159265359 * std::atan((X - x0) / a);
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