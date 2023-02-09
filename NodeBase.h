#pragma once
#include "Entity.h"

class NodeBase;
typedef std::shared_ptr<NodeBase> NodeBasePtr;

class NodeBase : public ActiveEntity
{
private:
    
public:
    float bias = 0.0f;
    NodeBase() = default;
    ~NodeBase() = default;
    virtual float activationFunction(float input) = 0;
    virtual float activationFunctionDerivative(float input) = 0;
    virtual float activationInput();
    virtual float derivativeInput();
    void CalculateActivation();
    void CalculateDerivative();
    void UpdateBias();
};