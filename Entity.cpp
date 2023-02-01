#include "Entity.h"

void Entity::SetForwardsConnection(Entity& fwdConnection)
{
    forwardConnections = &fwdConnection;
}

void Entity::SetBackwardsConnection(Entity& bckConnection)
{
    backwardsConnections = &bckConnection;
}

Entity& Entity::operator<<(Entity& fwdConnection)
{
    SetForwardsConnection(fwdConnection);
    fwdConnection.SetBackwardsConnection(*this);
    return fwdConnection;
}

void Entity::printActivation()
{
    std::cout << getActivation() << std::endl;
}

void Entity::printDerivative()
{
    std::cout << getDerivative() << std::endl;
}

float ActiveEntity::getActivation()
{
    return activation;
}

float ActiveEntity::getDerivative()
{
    return derivative;
}