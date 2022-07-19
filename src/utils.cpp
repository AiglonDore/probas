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
        throw Exception(ExceptionType::Calculus,"Gamma function is defined on positive real numbers.");
    }
    return Utils::Operators::integral(true,[&x](double t){ return std::pow(t,x - 1) * std::exp(-t); },0);
}

double Utils::Gamma(double x, double lambda)
{
    if (x < 0) throw Exception(ExceptionType::Calculus,"Incomplete Gamma function is defined on positive real numbers.");
    if (lambda < 0) throw Exception(ExceptionType::Calculus,"Undefined integration interval for incomplete Gamma function.");
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

double Utils::Operators::integral(std::function<double(double)>&& f,double a, double b)
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

double Utils::Operators::integral(bool positiveInfinite,const std::function<double(double)>& f, double a)
{
    double b((a + 1) * 10),deltaI,I;
    if (positiveInfinite)//Integral between a and +infinity
    {
        do
        {
            b *= 10;
            deltaI = Utils::Operators::integral(f,b,2 * b);
            I = Utils::Operators::integral(f,a,b);
        } while (abs(deltaI / I) >= 10e-50);
        return I;
    }
    //Integral between -infinity and a
    b *= -1;
    do
    {
        b *= 10;
        deltaI = Utils::Operators::integral(f,2 * b,b);
        I = Utils::Operators::integral(f,b,a);
    } while (abs(deltaI / I) >= 10e-50);
    return I;
}

double Utils::Operators::integral(bool positiveInfinite,std::function<double(double)>&& f, double a)
{
    double b((a + 1) * 10),deltaI,I;
    if (positiveInfinite)//Integral between a and +infinity
    {
        do
        {
            b *= 10;
            deltaI = Utils::Operators::integral(f,b,2 * b);
            I = Utils::Operators::integral(f,a,b);
        } while (abs(deltaI / I) >= 10e-50);
        return I;
    }
    //Integral between -infinity and a
    b *= -1;
    do
    {
        b *= 10;
        deltaI = Utils::Operators::integral(f,2 * b,b);
        I = Utils::Operators::integral(f,b,a);
    } while (abs(deltaI / I) >= 10e-50);
    return I;
}

double Utils::Operators::integral(const std::function<double(double)>& f)
{
    return Utils::Operators::integral(false,f,0) + Utils::Operators::integral(true,f,0);
}

double Utils::Operators::integral(std::function<double(double)>&& f)
{
    return Utils::Operators::integral(false,f,0) + Utils::Operators::integral(true,f,0);
}