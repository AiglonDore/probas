/**
 * @file normallaw.h
 * @author AiglonDore
 * @brief Provides the {@link NormalLaw} class.
 * @version 0.1
 * @date 2022-07-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef NORMALLAW_H
#define NORMALLAW_H

#include "continuouslaw.h"

#include <cmath>

/**
 * @brief This class provides tools to deal with normal laws.
 * 
 */
class NormalLaw : public ContinuousLaw
{
private:
    double mu;
    double sigma2;
public:
    /**
     * @brief Construct a new Normal Law object.
     * 
     */
    NormalLaw();
    /**
     * @brief Construct a new Normal Law object.
     * 
     * @param mu Expectancy.
     * @param sigma2 Variance.
     * @throws Exception if sigma <= 0.
     */
    NormalLaw(double mu, double sigma2);
    /**
     * @brief Destroy the Normal Law object.
     * 
     */
    virtual ~NormalLaw();

    /**
     * @brief Get the Mu object.
     * 
     * @return double Expectancy.
     */
    double getMu() const { return mu; };

    /**
     * @brief Get the Sigma2 object.
     * 
     * @return double Variance.
     */
    double getSigma2() const { return sigma2; };

    /**
     * @brief Overrides {@link Law} method for direct access.
     * 
     * @return double Standard deviation.
     */
    double stdDev() override {return std::sqrt(sigma2); };

    /**
     * @brief Overrides {@link Law} method.
     * 
     * @return double Expectancy.
     */
    double expectancy() override { return mu; };

    /**
     * @brief Overrides {@link Law} method.
     * 
     * @return double Variance.
     */
    double variance() override { return sigma2; };
};


#endif //NORMALLAW_H