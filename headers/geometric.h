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
public:
    /**
     * @brief Construct a new Geometric Law object
     * 
     */
    explicit GeometricLaw();
    /**
     * @brief Construct a new Geometric Law object.
     * @throws Exception if p is not between 0 and 1.
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
     * @return double Variance.
     */
    virtual double repartition(double X) override;
};

/**
 * @brief The HyperGeometricLaw class deals with hypergeometric laws.
 */
class HyperGeometricLaw : public GeometricLaw
{
private:
    long long int n;
    long long int A;
public:
    /**
     * @brief Construct a new Hyper Geometric Law object.
     * 
     */
    explicit HyperGeometricLaw();
    /**
     * @brief Construct a new Hyper Geometric Law object
     * 
     * @param n First parameter of law.
     * @param p Second law parameter.
     * @param A Third law parameter.
     */
    explicit HyperGeometricLaw(long long int n, double p, long long int A);
    /**
     * @brief Destroy the Hyper Geometric Law object
     * 
     */
    virtual ~HyperGeometricLaw();

    /**
     * @brief Returns n.
     * 
     * @return long long int n.
     */
    long long int getN() const { return n; };

    /**
     * @brief Returns A.
     * 
     * @return long long int A.
     */
    long long int getA() const { return A; };

    /**
     * @brief Overrides {@link GeometricLaw} function.
     * 
     * @return double Probability.
     */
    virtual double proba(long long int X) override;

    /**
     * @brief Overrides {@link GeometricLaw} function.
     * 
     * @return double Expectancy.
     */
    virtual double expectancy() override;

    /**
     * @brief Overrides {@link GeometricLaw} function.
     * 
     * @return double Variance.
     */
    virtual double variance() override;
    /**
     * @brief Overrides {@link GeometricLaw} function.
     * @param X value.
     * @return double F(X).
     */
    virtual double repartition(double X) override;
};

#endif //GEOMETRIC_H