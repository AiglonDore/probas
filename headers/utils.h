/**
 * @file utils.h
 * @author AiglonDore
 * @brief Provides useful functions.
 * @version 0.1
 * @date 2022-07-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef UTILS_H
#define UTILS_H

/**
 * @brief Holds several useful functions.
 * 
 */
namespace Utils {
    /**
     * @brief Computes n!.
     * 
     * @param n Value.
     * @return int n!.
     */
    long long int fact(long long int n);

    /**
     * @brief Returns the binomial coefficient.
     * 
     * @param n Number of items.
     * @param k Number of slices.
     * @return int Binomial coefficient.
     */
    long long int nCr(long long int n, long long int k);

    /**
     * @brief Number of permutations.
     * 
     * @param n Number of itmes.
     * @param k Number of selected items.
     * @return long long int Number of permutations.
     */
    long long int nPr(long long int n, long long int k);
    
    /**
     * @brief Gamma function.
     * 
     * @param x Value.
     * @return double Gamma(x).
     * @throws -1 if x < 0.
     * @todo Write function.
     */
    double Gamma(double x);

    /**
     * @brief Incomplete Gamma function.
     * 
     * @param x Value.
     * @param lambda Parameter.
     * @return double Value of function.
     * @throws -1 if x < 0 or lambda < 0
     * @todo Write function.
     */
    double Gamma(double x, double lambda);
}
#endif //UTILS_H