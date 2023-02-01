#pragma once
#include "mnistReader.h"
#include "Layer.h"

class Network
{
private:
    LayerBase* layers;
public:
    Network(mnistReader images, mnistReader labels, const int sizeHL1, const int sizeHL2);
    ~Network();
};
