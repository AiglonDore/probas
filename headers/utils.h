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
}
#endif //UTILS_H