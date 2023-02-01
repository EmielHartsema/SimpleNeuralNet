#include "Connection.h"

float Connection::getActivation()
{
    return backwardsConnections->getActivation() * weight;
}

float Connection::getDerivative()
{
    // return dC/dA given dC/dz
    float derivative = forwardConnections->getDerivative() * weight;
    updateWeight();
    return derivative;
}

void Connection::updateWeight()
{
    weight += forwardConnections->getDerivative() * backwardsConnections->getActivation();
}