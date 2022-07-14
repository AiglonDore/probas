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

#include <functional>

/**
 * @brief Holds several useful functions.
 * 
 */
namespace Utils {
    /**
     * @brief Provides several operators (integral,...);
     * 
     */
    namespace Operators {
        /**
         * @brief Returns the integral of f between a and b.
         * @param f Function.
         * @param a Lower bound.
         * @param b Upper bound.
         * @return double Integral.
         */
        double integral(const std::function<double(double)>& f,double a, double b);

        /**
         * @brief Returns the integral of f between a and b.
         * @param f Function.
         * @param a Lower bound.
         * @param b Upper bound.
         * @return double Integral.
         */
        double integral(std::function<double(double)>&& f, double a, double b);

        /**
         * @brief Returns the integral of f between -infinity and a, or between a and +infinity if positiveInfinite is true.
         * @throws false if integral is infinite.
         * @param f Function.
         * @param a Bound.
         * @param positiveInfinite Determines the integration interval (]-infinity;a] if false or [a;+infinity[ if true).
         * @return double INntegral of the selected interval.
         */
        double integral(bool positiveInfinite,const std::function<double(double)>& f, double a);

        /**
         * @brief Returns the integral of f between -infinity and a, or between a and +infinity if positiveInfinite is true.
         * @throws false if integral is infinite.
         * @param f Function.
         * @param a Bound.
         * @param positiveInfinite Determines the integration interval (]-infinity;a] if false or [a;+infinity[ if true).
         * @return double INntegral of the selected interval.
         */
        double integral(bool positiveInfinite,std::function<double(double)>&& f, double a);

        /**
         * @brief Integrates f on R.
         * @throws false if integral is infinite.
         * @param f Function
         * @return double Integral of f on R.
         */
        double integral(const std::function<double(double)>& f);
        /**
         * @brief Integrates f on R.
         * @throws false if integral is infinite.
         * @param f Function
         * @return double Integral of f on R.
         */
        double integral(std::function<double(double)>&& f);
    };
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
     */
    double Gamma(double x);

    /**
     * @brief Incomplete Gamma function.
     * 
     * @param x Value.
     * @param lambda Parameter.
     * @return double Value of function.
     * @throws -1 if x < 0 or lambda < 0
     */
    double Gamma(double x, double lambda);
}
#endif //UTILS_H