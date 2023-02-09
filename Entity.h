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
private:

protected:
    std::vector<EntityPtr> forwardConnections;
    std::vector<EntityPtr> backwardsConnections;
    
public:
    Entity() = default;
    ~Entity() = default;
    virtual float getActivation() = 0;
    virtual float getDerivative() = 0;
    void SetForwardsConnection(EntityPtr fwdConnection);
    void SetBackwardsConnection(EntityPtr bckConnection);

    void printActivation();
    void printDerivative();
};

class ActiveEntity : public Entity
{
private:

protected:
    float activation = 0.0f;
    float derivative = 0.0f;
public:
    ActiveEntity() = default;
    ~ActiveEntity() = default;
    virtual void CalculateActivation() = 0;
    virtual void CalculateDerivative() = 0;
    float getActivation();
    float getDerivative();
};

class PassiveEntity : public Entity
{
private:

protected:

public:
    PassiveEntity() = default;
    ~PassiveEntity() = default;
};