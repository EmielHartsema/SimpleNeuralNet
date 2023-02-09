#include "Network.h"

Network::Network(mnistImages& images, std::vector<int>& hiddenLayerSizes,mnistLabels& labels)
{
    // Create input layer
    layers.push_back(std::make_shared<InputLayer>(images));

    // Create hidden layers
    for (int hiddenlayersize : hiddenLayerSizes)
    {
        layers.push_back(std::make_shared<HiddenLayer>(hiddenlayersize));
    }    

    // Create output layer
    layers.push_back(std::make_shared<OutputLayer>(labels));

    // Connect layers
    for (int i = 0; i < static_cast<int>(layers.size())-1 ; i++)
    {
        *layers[i]<<*layers[i+1];
    }
}

Network::~Network()
{
}

void Network::PropogateForward()
{
    for (auto layer : layers)
    {
        layer->CalculateActivation();
    }
}

void Network::PropogateBackwards()
{
    for (int i=layers.size()-1; i>=0; i--)
    {
        std::cout << "i = " << i << std::endl;
        layers[i]->CalculateDerivative();
    }
}

void Network::PrintOutputLayer()
{
    layers.back()->PrintLayer();
}