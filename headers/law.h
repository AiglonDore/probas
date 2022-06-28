/**
 * @file law.h
 * @author AiglonDore
 * @brief Provides the abstract class {@link Law}.
 * @version 0.2
 * @date 2022-06-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef LAW_H
#define LAW_H

#include <cmath>

/**
 * @brief The class Law provides a generic class that will hold all the sub-classes relative to specific laws.
 * 
 */
class Law
{
public:
    /**
     * @brief Destroys the Law object.
     * 
     */
    virtual ~Law() {};
    /**
     * @brief Computes the probability. Exactly, it will return the value of the density function at this point.
     * 
     * @param x Value.
     * @return double Probability.
     */
    virtual double proba(double x)=0;

    /**
     * @brief Computes the probability. Exactly, it will return the integral of the density function in the selected interval.
     * 
     * @param lowerBound Lower value.
     * @param upperBound Upper value.
     * @return double Probability.
     */
    virtual double proba(double lowerBound, double upperBound) = 0;

    /**
     * @brief Computes the probability. Exactly, it will return the value of the density function at this point.
     * 
     * @param x Value.
     * @return double Probability.
     */
    virtual double proba(long long int x)=0;

    /**
     * @brief Computes the probability. Exactly, it will return the integral of the density function in the selected interval.
     * 
     * @param lowerBound Lower value.
     * @param upperBound Upper value.
     * @return double Probability.
     */
    virtual double proba(long long int lowerBound, long long int upperBound) = 0;

    /**
     * @brief Computes the expectancy.
     * 
     * @return double Expectancy.
     */
    virtual double expectancy()=0;

    /**
     * @brief Computes the expectancy.
     * 
     * @return double Variance.
     */
    virtual double variance()=0;

    /**
     * @brief Computes the standard deviation.
     * 
     * @return double Standard deviation.
     */
    virtual double stdDev() { return std::sqrt(this->variance()); };
};

#endif //LAW_H