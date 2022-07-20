/**
 * @file continuouslaw.h
 * @author AiglonDore
 * @brief Provides the {@link ContinuousLaw} class to deal with discrete laws.
 * @version 0.1
 * @date 2022-06-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef DISCRETELAW_H
#define DISCRETELAW_H

#include "../headers/law.h"
#include <functional>

/**
 * @brief The ContinuousLaw class deals with continuous laws on R.
 * @warning This requires that all sub-classes will implement the repartition function to adjust the integration interval (regarding the calculus methods).
 */
class ContinuousLaw : public Law
{
protected:
/**
 * @brief Contains the density function of the continuous law.
 * 
 */
    std::function<double(double)> densityFunction;
public:
    /**
     * @brief Destroys the Continuous Law object.
     * 
     */
    virtual ~ContinuousLaw() {};

/**
     * @brief Computes the probability.
     * 
     * @param x Value.
     * @return double Probability.
     */
    virtual double proba(long long int x) override final;

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
    virtual double proba(double X) override final;

    /**
     * @brief Overrides {@link Law} function.
     * 
     * @param lowerBound Lower value.
     * @param upperBound Upper value.
     * @return double Probability.
     */
    virtual double proba(double lowerBound, double upperBound) override final;

    /**
     * @brief Overrides {@link Law} function.
     * 
     * @param lowerBound Lower value.
     * @param upperBound Upper value.
     * @return double Probability.
     */
    virtual double proba(long long int lowerBound, long long int upperBound) override final;

    /**
     * @brief Overrides {@link Law} function.
     * 
     * @param X Value.
     * @return double f(X).
     */
    virtual double density(double X) override final;
    /**
     * @brief Overrides {@link Law} function.
     * 
     * @param X Value.
     * @return double F(X).
     */
    virtual double repartition(double X) override;

    /**
     * @brief Get the Density Function object.
     * 
     * @return const std::function<double(double)>& for density function.
     */
    const std::function<double(double)>& getDensityFunction() const { return densityFunction; };
};

#endif //DISCRETELAW_H