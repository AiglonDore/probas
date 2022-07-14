/**
 * @file benford.h
 * @author AiglonDore
 * @brief Provides the {@link BenfordLaw} class.
 * @version 0.1
 * @date 2022-07-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef BENFORD_H
#define BENFORD_H

#include "discretelaw.h"

/**
 * @brief The class BenfordLaw deals with Benford laws.
 * 
 */
class BenfordLaw : public DiscreteLaw
{
private:
    unsigned long long int base;
public:
    /**
     * @brief Construct a new Benford Law object
     * 
     */
    explicit BenfordLaw();
    /**
     * @brief Construct a new Benford Law object.
     * 
     * @param base Base for the logarithm.
     * @throws @{link Exception} if base < 2.
     */
    explicit BenfordLaw(unsigned long long int base);
    /**
     * @brief Destroy the Benford Law object
     * 
     */
    virtual ~BenfordLaw();
    /**
     * @brief Get the Base object.
     * 
     * @return const unsigned long long& Value of the base.
     */
    const unsigned long long int& getBase() const { return base; };

        /**
     * @brief Overrides {@link Law} function.
     * 
     * @param X Value.
     * @return double Probability.
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


#endif //BENFORD_H