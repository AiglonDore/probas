/**
 * @file geometric.h
 * @author AiglonDore
 * @brief Provides tools for geometric laws.
 * @version 0.1
 * @date 2022-07-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef GEOMETRIC_H
#define GEOMETRIC_H

#include "bernoulli.h"

/**
 * @brief The GeometricLaw class provides tools to deal with geometric laws.
 * 
 */
class GeometricLaw : public BernoulliLaw
{
private:
    /* data */
public:
    /**
     * @brief Construct a new Geometric Law object
     * 
     */
    explicit GeometricLaw();
    /**
     * @brief Construct a new Geometric Law object.
     * 
     * @param p Parameter.
     */
    explicit GeometricLaw(double p);
    /**
     * @brief Destroys the Geometric Law object.
     * 
     */
    virtual ~GeometricLaw();

    /**
     * @brief Overrides {@link BernoulliLaw} function.
     * 
     * @param X Value.
     * @return double Probability.
     * @throws -1 if X is negative or null
     */
    virtual double proba(long long int X) override;

    /**
     * @brief Overrides {@link BernoulliLaw} function.
     * 
     * @return double Expectancy.
     */
    virtual double expectancy() override;

    /**
     * @brief Overrides {@link BernoulliLaw} function.
     * 
     * @return double Variance.
     */
    virtual double variance() override;
};

#endif //GEOMETRIC_H