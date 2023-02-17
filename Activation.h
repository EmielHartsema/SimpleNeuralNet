#pragma once
#include "Entity.h"

class Activation : public Entity
{
private:

public:
    Activation() = default;
    ~Activation() = default;
    virtual float GetActivation() = 0;
    virtual float GetDerivative() = 0;
    virtual void CalcActivation() = 0;
    virtual void CalcDerivative() = 0;


};

class ActiveActivation : public Activation
{
private:
    float activation_;
    float derivative_;
public:
    ActiveActivation() = default;
    ~ActiveActivation() = default;
    float GetActivation() { return activation_ };
    float GetActivation() { return derivative_ };
};

class PassiveActivation : public Activation
{
private:
public:
    PassiveActivation() = default;
    ~PassiveActivation() = default;
    float GetActivation() { return CalcActivation() };
    float GetActivation() { return CalcDerivative() };
};