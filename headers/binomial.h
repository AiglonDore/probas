/**
 * @file binomial.h
 * @author AiglonDore
 * @brief Provides the binomial law class.
 * @version 0.1
 * @date 2022-06-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef BINOMIAL_H
#define BINOMIAL_H

#include "bernoulli.h"

/**
//  * @brief The BinomialLaw class extends the {@link BernoulliLaw} to provide binomial law tools.
 * 
 */
class BinomialLaw : public BernoulliLaw
{
private:
    long long int n;
public:
    /**
     * @brief Constructs a new Binomial Law object.
     * 
     */
    BinomialLaw();
    /**
     * @brief Constructs a new Binomial Law object.
     * 
     * @param p Law parameter.
     */
    BinomialLaw(double p);
    /**
     * @brief Constructs a new Binomial Law object.
     * 
     * @param n Number of trials.
     * @param p Law parameter.
     * @throws Exception if n is negative.
     */
    BinomialLaw(long long int n, double p);
    /**
     * @brief Destroys the Binomial Law object.
     * 
     */
    virtual ~BinomialLaw();

    /**
     * @brief Gets the number of trials.
     * 
     * @return int Number of trials.
     */
    long long unsigned int getN() const { return n; };

    /**
     * @brief Overrides {@link BernoulliLaw} function.
     * 
     * @param X Value.
     * @return double Probability.
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

    /**
     * @brief Overrides {@link BernoulliLaw} function.
     * 
     * @param X Value.
     * @return double F(X).
     */
    virtual double repartition(double X) override;
};

#endif //BINOMIAL_H