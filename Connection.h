#pragma once
#include "Entity.h"

class Connection : public PassiveEntity
{
private:
    float weight = 0.1f;
    void updateWeight();
public:
    Connection() = default;
    ~Connection() = default;
    float getActivation();
    float getDerivative();
};

typedef std::shared_ptr<Connection> ConnectionPtr;