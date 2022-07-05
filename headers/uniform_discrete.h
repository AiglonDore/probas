/**
 * @file uniform_discrete.h
 * @author AiglonDore
 * @brief Uniform discrete law.
 * @version 0.1
 * @date 2022-06-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef UNIFORMD_H
#define UNIFORMD_H

#include "discretelaw.h"

/**
 * @brief This class provides tools for uniform discrete laws.
 * 
 */
class UniformDiscreteLaw : public DiscreteLaw
{
private:
    long long int lowerBound;
    long long int upperBound;
    long long int n;
public:
    /**
     * @brief Constructs a new Uniform Discrete Law object, between 0 and 1.
     * 
     */
    UniformDiscreteLaw();

    /**
     * @brief Constructs a new Uniform Discrete Law object.
     * 
     * @param upperBound Value for upperbound.
     * @throws 1 if upperBound is negative or null.
     */
    UniformDiscreteLaw(long long int upperBound);
    
    /**
     * @brief Constructs a new Uniform Discrete Law object.
     * 
     * @param lowerBound Value for lower bound.
     * @param upperBound Value for upperbound.
     * @throws 1 if upperBound is lower than lowerBound.
     */
    UniformDiscreteLaw(long long int lowerBound, long long int upperBound);

    /**
     * @brief Destroys the Uniform Discrete Law object.
     * 
     */
    virtual ~UniformDiscreteLaw();

    /**
     * @brief Get the Lower Bound object.
     * 
     * @return int Lower bound.
     */
    long long int getLowerBound() const { return lowerBound; };

    /**
     * @brief Get the Upper Bound object.
     * 
     * @return int Upper bound.
     */
    long long int getUpperBound() const { return upperBound; };

    /**
     * @brief Gets the number of elements in the support.
     * 
     * @return int n.
     */
    long long int getN() const { return n; };

    /**
     * @brief Overrides {@link DiscreteLaw} function.
     * 
     * @param X Value.
     * @return double Probability.
     * @throws 0 if X is out of bounds.
     */
    virtual double proba(long long int X) override;

    /**
     * @brief Overrides {@link DiscreteLaw} function.
     * @return double Expectancy.
     */
    virtual double expectancy() override;

    /**
     * @brief Overrides {@link DiscreteLaw} function.
     * 
     * @return double Variance.
     */
    virtual double variance() override;
/**
     * @brief Overrides {@link DiscreteLaw} function.
     * @param X Value
     * @return double F(X).
     */
    virtual double repartition(double X) override;
};


#endif //UNIFORMD_H