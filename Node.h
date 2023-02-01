#pragma once
#include "NodeBase.h"

class HiddenNode : public NodeBase
{
private:
    
public:
    HiddenNode() = default;
    ~HiddenNode() = default;
    float activationFunction(float input);
    float activationFunctionDerivative(float input);
};

class InputNode : public NodeBase
{
private:

public:
    InputNode() = default;
    ~InputNode() = default;
    float activationFunction(float input);
    float activationFunctionDerivative(float input);
    float activationInput() override;
};

class OutputNode : public NodeBase
{
private:

public:
    OutputNode() = default;
    ~OutputNode() = default;
    float activationFunction(float input);
    float activationFunctionDerivative(float input);
};