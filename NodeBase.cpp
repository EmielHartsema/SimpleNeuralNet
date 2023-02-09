#include "Node.h"

float NodeBase::activationInput()
{
    float buffer = 0.0f;
    for (EntityPtr bckconnection : backwardsConnections)
    {
        buffer += bckconnection->getActivation();
    }
    return buffer;
}

float NodeBase::derivativeInput()
{
    float buffer = 0.0f;
    for (EntityPtr fwdconnection : forwardConnections)
    {
        buffer += fwdconnection->getActivation();
    }
    return buffer;
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