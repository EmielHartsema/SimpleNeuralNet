#include "Entity.h"

void Entity::SetForwardsConnection(EntityPtr fwdConnection)
{
    forwardConnections.push_back(fwdConnection);
}

void Entity::SetBackwardsConnection(EntityPtr bckConnection)
{
    backwardsConnections.push_back(bckConnection);
}

float Entity::GetActivationInput()
{
    float buffer = 0.0f;
    for (EntityPtr entityPtr : backwardsConnections)
    {
        buffer = buffer + entityPtr->GetActivation();
    }
    return buffer;
}

float Entity::GetDerivativeInput()
{
    float buffer = 0.0f;
    for (EntityPtr entityPtr : forwardConnections)
    {
        buffer = buffer + entityPtr->GetDerivative();
    }
    return buffer;
}