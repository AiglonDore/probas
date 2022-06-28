/**
 * @file bernoulli.h
 * @author AiglonDore
 * @brief Provides functions relted to the Bernoulli law.
 * @version 0.1
 * @date 2022-06-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef BERNOULLI_H
#define BERNOULLI_H

#include "discretelaw.h"

/**
 * @brief The class BernoulliLaw provides tools to dela with Bernoulli laws.
 * 
 */
class BernoulliLaw : public DiscreteLaw
{
protected:
    double p;
public:
    /**
     * @brief Constructs a new Bernoulli Law object with p = 0.5.
     * 
     */
    BernoulliLaw();

    /**
     * @brief Construct a new Bernoulli Law object
     * 
     * @param p Parameter of the law.
     * @throws 0 if p not in [0;1].
     */
    BernoulliLaw(double p);

    /**
     * @brief Destroys the Bernoulli Law object.
     * 
     */
    ~BernoulliLaw();

    /**
     * @brief Gets the Bernoulli law parameter.
     * 
     * @return double p.
     */
    double getP() const { return p; };

    /**
     * @brief Overrides {@link Law} function.
     * 
     * @param X Value.
     * @return double Probability.
     * @throws -1 if X is not 0 or 1.
     */
    virtual double proba(long long int X) override;

    /**
     * @brief Overrides {@link Law} function.
     * 
     * @return double Expectancy.
     */
    virtual double expectancy() override;

    /**
     * @brief Overrides {@link Law} function.
     * 
     * @return double Variance.
     */
    virtual double variance() override;
};


#endif //BERNOULLI_H