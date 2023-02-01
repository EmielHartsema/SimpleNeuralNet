#pragma once
#include "Entity.h"

class Connection : public PassiveEntity
{
private:
    float weight = 10.0f;
    void updateWeight();
public:
    Connection() = default;
    ~Connection() = default;
    float getActivation();
    float getDerivative();
};