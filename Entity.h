// Entity.h
//
// The Entity class is a base class of anything that has activation value.
//
// Author: Emiel Hartsema
// Date: 24-1-2023
#pragma once
#include <iostream>
#include <memory>
#include <vector>

class Entity;
typedef std::shared_ptr<Entity> EntityPtr;


class Entity
{
protected:
    std::vector<EntityPtr> forwardConnections;
    std::vector<EntityPtr> backwardsConnections;
    
public:
    Entity() = default;
    ~Entity() = default;
    float GetActivationInput();
    float GetDerivativeInput();
    virtual float GetActivation() = 0;
    virtual float GetDerivative() = 0;
    virtual float CalculateActivation() = 0;
    virtual float CalculateDerivative() = 0;
    virtual void UpdateActivation() {};
    virtual void UpdateDerivative() {};
    void SetForwardsConnection(EntityPtr fwdConnection);
    void SetBackwardsConnection(EntityPtr bckConnection);
};

class ActiveEntity : public Entity
{
private:
    float activation_ = 0.0f;
    float derivative_ = 0.0f;
public:
    float GetActivation() { return activation_; };
    float GetDerivative() { return derivative_; };
    void UpdateActivation() { activation_ = CalculateActivation(); };
    void UpdateDerivative() { derivative_ = CalculateDerivative(); };
};

class PassiveEntity : public Entity
{
public:
    float GetActivation() { return CalculateActivation(); };
    float GetDerivative() { return CalculateDerivative(); };
};