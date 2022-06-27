/**
 * @file law.h
 * @author AiglonDore
 * @brief Provides the abstract class {@link Law}.
 * @version 0.1
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
    virtual ~Law();
    /**
     * @brief Computes the probability.
     * 
     * @param x Value.
     * @return double Probability.
     */
    virtual double proba(double x)=0;

    /**
     * @brief Computes the probability.
     * 
     * @param x Value.
     * @return double Probability.
     */
    virtual double proba(long long int x)=0;

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
     * @brief Computes the m-moment.
     * 
     * @param m Moment.
     * @return double Value of the moment.
     */
    virtual double moment(long long unsigned int m = 1) = 0;

    /**
     * @brief Computes the standard deviation.
     * 
     * @return double Standard deviation.
     */
    virtual double stdDev() { return std::sqrt(this->variance()); };
};

#endif //LAW_H