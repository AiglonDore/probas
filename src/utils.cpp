/**
 * @file utils.cpp
 * @author AiglonDore
 * @brief Implements {@link utils.h}.
 * @version 0.1
 * @date 2022-07-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <cmath>

#include "../headers/utils.h"

long long int Utils::fact(long long int n)
{
    long long int p = 1;
    for (long long int i = 1; i <= n; i++)
    {
        p *= i;
    }
    return p;
}

long long int Utils::nCr(long long int n, long long int k)
{
    if (n < 0 || k < 0 || k > n)
    {
        return 0;
    }
    return Utils::fact(n) / (Utils::fact(k) * Utils::fact(n - k));
}

long long int Utils::nPr(long long int n, long long int k)
{
    return nCr(n,k) * fact(k);
}

double Utils::Gamma(double x)
{
    if (x <= 0)
    {
        throw -1;
    }
    auto f = [&x](double t){
        return std::pow(t,x - 1) * std::exp(-t);
    };
    return 0.0;
}

double Utils::Gamma(double x, double lambda)
{
    return Utils::Operators::integral([&x](double t){ return std::pow(t,x - 1) * std::exp(-t); },0,lambda);
}

double Utils::Operators::integral(const std::function<double(double)>& f,double a, double b)
{
    int n = 100;
    double h = (b - a) / n;
    double s0 = 0.0;
    double s1 = 0.0;
    for (int j = 0; j < n; j++)
    {
        s0 += f(a + j * h);
        s1 += f(a + (2 * (j + 1) - 1) * h / 2);
    }
    return h / 6 * (f(a) + 2 * s0 + 4 * s1 + f(b));
}