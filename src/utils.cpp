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