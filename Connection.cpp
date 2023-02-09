#include "Connection.h"

float Connection::getActivation()
{
    return backwardsConnections[0]->getActivation() * weight;
}

float Connection::getDerivative()
{
    // return dC/dA given dC/dz
    float derivative = forwardConnections[0]->getDerivative() * weight;
    updateWeight();
    return derivative;
}

void Connection::updateWeight()
{
    weight -= forwardConnections[0]->getDerivative() * backwardsConnections[0]->getActivation();
}