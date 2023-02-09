#pragma once
#include <memory>
#include "mnistReader.h"
#include "Layer.h"

class Network
{
private:
    std::vector<std::shared_ptr<LayerBase>> layers;
public:
    Network(mnistImages& images, std::vector<int>& hiddenLayerSizes,mnistLabels& labels);
    ~Network();
    void PropogateForward();
    void PropogateBackwards();
    void PrintOutputLayer();
};
