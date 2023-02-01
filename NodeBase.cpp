#include "Node.h"

float NodeBase::activationInput()
{
    return backwardsConnections->getActivation();
}

float NodeBase::derivativeInput()
{
    return forwardConnections->getDerivative();
}

void NodeBase::CalculateActivation()
{
    activation = activationFunction(activationInput() + bias);
}

void NodeBase::CalculateDerivative()
{
    // Return dC/dz given derivativeInput (dC/da)
    derivative = activationFunctionDerivative(activation) * derivativeInput();
    UpdateBias();
}

void NodeBase::UpdateBias()
{
    bias -= derivative;
}