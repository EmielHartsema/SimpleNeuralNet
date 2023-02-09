#pragma once
#include "mnistReader.h"
#include "Node.h"
#include "Connection.h"

class LayerBase
{
protected:
    std::vector<NodeBasePtr> nodes;
public:
    LayerBase() = default;
    ~LayerBase() = default;
    LayerBase& operator<<(LayerBase& nextLayer);
    void CalculateActivation();
    void CalculateDerivative();
    void PrintLayer();
};

class InputLayer : public LayerBase
{
    public:
    InputLayer(mnistReader images);
};

class HiddenLayer : public LayerBase
{
    public:
    HiddenLayer(int size);
};

class OutputLayer : public LayerBase
{
    public:
    OutputLayer(mnistReader labels);
};