/**
 * @file law.h
 * @author AiglonDore
 * @brief Provides the abstract class {@link Law}.
 * @version 0.1
 * @date 2022-06-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef LAW_H
#define LAW_H

/**
 * @brief The class Law provides a generic class that will hold all the sub-classes relative to specific laws.
 * 
 */
class Law
{
public:
    virtual double proba(double x)=0;
    virtual double proba(long long unsigned int x)=0;
    virtual double mean()=0;
    virtual double stdDev()=0;
    virtual ~Law();
};

double computeProbability(double X, const Law& law);

#endif //LAW_H