/**
 * @file poisson.h
 * @author AiglonDore
 * @brief Provides tools for Poisson laws.
 * @version 0.1
 * @date 2022-07-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef POISSON_H
#define POISSON_H

#include "discretelaw.h"
#include "utils.h"

/**
 * @brief The class PoissonLaw deals with Poisson laws.
 * 
 */
class PoissonLaw : public DiscreteLaw
{
private:
    double lambda;
public:
    /**
     * @brief Construct a new Poisson Law object. Lambda will have value 1.
     * 
     */
    explicit PoissonLaw();
    /**
     * @brief Construct a new Poisson Law object
     * @throws -1 if lambda < 0.
     * @param lambda Law parameter.
     */
    explicit PoissonLaw(double lambda);
    /**
     * @brief Destroy the Poisson Law object
     * 
     */
    virtual ~PoissonLaw();

    /**
     * @brief Get the Lambda object.
     * 
     * @return double 
     */
    double getLambda() const { return lambda; };

    /**
     * @brief Computes the probability.
     * 
     * @param x Value.
     * @return double Probability.
     */
    virtual double proba(long long int x);

    /**
     * @brief Computes the expectancy.
     * 
     * @return double Expectancy.
     */
    virtual double expectancy();

    /**
     * @brief Computes the expectancy.
     * 
     * @return double Variance.
     */
    virtual double variance();

    /**
     * @brief Adds a PoissonLaw to the current one.
     * 
     * @param other Other law to add.
     * @return PoissonLaw& This object, as a reference.
     */
    PoissonLaw& operator+=(const PoissonLaw& other);
};

/**
 * @brief Sums two {@link PoissonLaw} objects.
 * 
 * @param first First item to sum.
 * @param second Second item to sum
 * @return PoissonLaw Sum of both items.
 */
PoissonLaw operator+(const PoissonLaw& first, const PoissonLaw& second);

#endif //POISSON_H