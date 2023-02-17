#pragma once
//#include "Activation.h"

/*
class ActivationFunction
{
    public:
    ActivationFunction() = default;
    ~ActivationFunction() = default;

    virtual float CalculateActivation(float input, float parameter) = 0;
    virtual float CalculateDerivative(float input, float parameter) = 0;
};
*/

//class Identity : public ActivationFunction
class Identity
{
public:
    Identity() = default;
    ~Identity() = default;
    static float CalculateActivation(float input, float parameter = 0);
    static float CalculateDerivative(float input, float parameter = 0);
};

//class Multiplication : public ActivationFunction
class Multiplication
{
public:
    Multiplication() = default;
    ~Multiplication() = default;
    static float CalculateActivation(float input, float parameter = 1);
    static float CalculateDerivative(float input, float parameter = 1);
};

//class Addition : public ActivationFunction
class Addition
{
public:
    Addition() = default;
    ~Addition() = default;
    static float CalculateActivation(float input, float parameter = 0);
    static float CalculateDerivative(float input, float parameter = 0);
};

//class ReLu : public ActivationFunction
class ReLu
{
public:
    ReLu() = default;
    ~ReLu() = default;
    static float CalculateActivation(float input, float parameter = 1) { return 1.0f; };
    static float CalculateDerivative(float input, float parameter = 1) { return 1.0f; };
};