#include "ActivationFunction.h"

float Identity::CalculateActivation(float input, float parameter)
{
    return input;
}

float Identity::CalculateDerivative(float input, float parameter)
{
    return 1.0f;
}

float Multiplication::CalculateActivation(float input, float parameter)
{
    return parameter * input;
}

float Multiplication::CalculateDerivative(float input, float parameter)
{
    return parameter;
}

float Addition::CalculateActivation(float input, float parameter)
{
    return parameter + input;
}

float Addition::CalculateDerivative(float input, float parameter)
{
    return 1.0f;
}

float ReLu::CalculateActivation(float input, float parameter)
{
    return (input > 0) ? parameter * input : 0;
}

float ReLu::CalculateDerivative(float input, float parameter)
{
    return (input > 0) ? parameter : 0;
}