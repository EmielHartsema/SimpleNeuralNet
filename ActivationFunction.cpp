#include "ActivationFunction.h"

float ReLu::activationFunction(float input)
{
    return (input>0) ? input : 0;
}