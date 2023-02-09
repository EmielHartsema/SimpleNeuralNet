#include "Layer.h"

LayerBase& LayerBase::operator<<(LayerBase& nextLayer)
{
    for (auto & thisLayerNode : nodes)
    {
        for (auto & NextLayerNode : nextLayer.nodes)
        {
            std::shared_ptr<Connection> conn = std::make_shared<Connection>();
            thisLayerNode->SetForwardsConnection(conn);

            conn->SetBackwardsConnection(thisLayerNode);
            conn->SetForwardsConnection(NextLayerNode);

            NextLayerNode->SetBackwardsConnection(conn);
        }
    }
    return nextLayer;
}

void LayerBase::CalculateActivation()
{
    for (NodeBasePtr node : nodes)
    {
        node->CalculateActivation();
    }
}

void LayerBase::CalculateDerivative()
{
    for (NodeBasePtr node : nodes)
    {
        node->CalculateDerivative();
    }
}

void LayerBase::PrintLayer()
{
    for (NodeBasePtr node : nodes)
    {
        node->printActivation();
        node->printDerivative();
    }
}

InputLayer::InputLayer(mnistReader images)
{
    for (int i = 0; i < images.imageRes * images.imageRes; i++)
    {
        nodes.push_back(std::make_shared<InputNode>());
    }
}

HiddenLayer::HiddenLayer(int size)
{
    for (int i = 0; i < size; i++)
    {
        nodes.push_back(std::make_shared<HiddenNode>());
    }
}

OutputLayer::OutputLayer(mnistReader labels)
{
    for (int i = 0; i < 10; i++)
    {
        nodes.push_back(std::make_shared<OutputNode>());
    }
}