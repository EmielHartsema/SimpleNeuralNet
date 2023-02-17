#pragma once
#include "NodeBase.h"
#include "Entity.h"
#include "Parameter.h"
#include "ActivationFunction.h"
#include "Activation.h"

template <Parameter paramtype, ActivationFunction ActivationFunctionType, Activation activationType>
class Node : public NodeBase, public Entity, public paramtype, public ActivationFunctionType, public activationType
{
private:
    
public:
    Node() = default;
    ~Node() = default;
    //getActivation()
    Entity::getActivation() { ActivationFunctionType::CalculateActivation(GetActivationInput(), paramtype::GetParameter()) }; // needed for interfacing with Entity
    Entity::getDerivative() { ActivationFunctionType::CalculateDerivative(GetDerivativeInput(), paramtype::GetParameter()) };

    //CalculateActivation(); // needed for interfacing with Activation
    //CalculateDerivative();
};