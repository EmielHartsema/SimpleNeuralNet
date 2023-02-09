#include "Entity.h"

void Entity::SetForwardsConnection(EntityPtr fwdConnection)
{
    forwardConnections.push_back(fwdConnection);
}

void Entity::SetBackwardsConnection(EntityPtr bckConnection)
{
    backwardsConnections.push_back(bckConnection);
}

void Entity::printActivation()
{
    std::cout << "Activation = " << getActivation() << std::endl;
}

void Entity::printDerivative()
{
    std::cout << "Derivative = " << getDerivative() << std::endl;
}

float ActiveEntity::getActivation()
{
    return activation;
}

float ActiveEntity::getDerivative()
{
    return derivative;
}