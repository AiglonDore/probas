/**
 * @file cauchylaw.h
 * @author AiglonDore
 * @brief Provides the {@link CauchyLaw} class.
 * @version 0.1
 * @date 2022-07-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef NORMALLAW_H
#define NORMALLAW_H

#include "continuouslaw.h"
#include "exn.hpp"

#include <cmath>

/**
 * @brief This class provides tools to deal with normal laws.
 * 
 */
class CauchyLaw : public ContinuousLaw
{
private:
    double a;
public:
    /**
     * @brief Construct a new Cauchy Law object.
     * 
     */
    CauchyLaw();
    /**
     * @brief Construct a new Cauchy Law object.
     * 
     * @param a Law parameter.
     * @throws Exception if a <= 0.
     */
    CauchyLaw(double a);
    /**
     * @brief Destroy the Cauchy Law object.
     * 
     */
    virtual ~CauchyLaw();

    /**
     * @brief Gets a.
     * 
     * @return double a. 
     */
    double getA() const { return a; };

    /**
     * @brief Overrides {@link ContinuousLaw} function to restrain integration domain.
     * 
     * @param X Value.
     * @return double 
     */
    double repartition(double X) override;

    /**
     * @brief Overrides {@link Law} method for direct access.
     * 
     * @return nothing.
     * @throws Always Exception.
     */
    double stdDev() override;

    /**
     * @brief Overrides {@link Law} method.
     * 
     * @return double Expectancy.
     * @throws Always Exception.
     */
    double expectancy() override;

    /**
     * @brief Overrides {@link Law} method.
     * 
     * @return double Variance.
     * @throws Always Exception.
     */
    double variance() override;
};


#endif //NORMALLAW_H