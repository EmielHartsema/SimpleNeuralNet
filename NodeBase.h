#pragma once
#include "Entity.h"
#include "ActivationFunction.h"
//class NodeBase;
//typedef std::shared_ptr<NodeBase<Entity>> NodeBasePtr;

template<typename entityType, typename activationFunctionType>
class NodeBase : public entityType
{
	float CalculateActivation() { return activationFunctionType::CalculateActivation(1.0f); };
	float CalculateDerivative() { return activationFunctionType::CalculateActivation(1.0f); };
};

/*
template<Entity entityType>
class TrainableNode : public NodeBase<entityType>
{

};

template<Entity entityType>
class StaticNode : public NodeBase<entityType>
{

};
*/