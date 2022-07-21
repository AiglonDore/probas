/**
 * @file normallaw.cpp
 * @author AiglonDore
 * @brief Implements {@link normallaw.h}.
 * @version 0.1
 * @date 2022-07-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "../headers/normallaw.h"
#include "../headers/exn.hpp"

#include <cmath>

using namespace std;

NormalLaw::NormalLaw() : mu(0), sigma2(1)
{
    densityFunction = [](double t){
        return 1 / sqrt(2 * 3.14159265359) * exp(- 0.5 * t * t);
    };
}

NormalLaw::NormalLaw(double mu, double sigma2) : mu(mu), sigma2(sigma2)
{
    if (sigma2 <= 0)
    {
        throw Exception(ExceptionType::Normal,"Variance of a normal law is always strictly positive");
    }
    densityFunction = [mu,sigma2](double t){
        return 1 / sqrt(2 * 3.14159265359 * sigma2) * exp(- 0.5 * pow((t - mu),2) / sigma2);
    };
}

NormalLaw::~NormalLaw()
{
}