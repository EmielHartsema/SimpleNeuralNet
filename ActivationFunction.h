#pragma once

class ActivationFunctionBase
{
    private:

    public:
    ActivationFunctionBase() = default;
    ~ActivationFunctionBase() = default;
    virtual float activationFunction(float input) = 0;
};

class ReLu : public ActivationFunctionBase
{
    float activationFunction(float input) override;
};