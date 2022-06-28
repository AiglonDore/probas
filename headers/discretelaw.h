/**
 * @file discretelaw.h
 * @author AiglonDore
 * @brief Provides the discrete law class to deal with discrete laws.
 * @version 0.1
 * @date 2022-06-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef DISCRETELAW_H
#define DISCRETELAW_H

#include "../headers/law.h"

/**
 * @brief The Discrete Law blocks the domains of Law to the relative numbers.
 * 
 */
class DiscreteLaw : public Law
{
public:
    /**
     * @brief Destroys the Discrete Law object.
     * 
     */
    virtual ~DiscreteLaw() {};

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
     * @brief Overrides {@link Law} function.
     * 
     * @param X Value.
     * @return double Probability.
     */
    virtual double proba(double X) override;
};

#endif //DISCRETELAW_H
