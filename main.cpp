#include <iostream>
#include "mnistReader.h"
#include "Network.h"
#include "Node.h"
#include "Connection.h"
#include <vector>
#include "Entity.h"
#include <memory>

int main()
{
    mnistImages mnistImages("./data/train-images-idx3.ubyte");
    mnistLabels mnistLabels("./data/train-labels-idx1.ubyte");
    
    /*
    InputNodePtr inNode = std::make_shared<InputNode>();
    OutputNodePtr outNode = std::make_shared<OutputNode>();
    std::shared_ptr<Connection> conn = std::make_shared<Connection>();

    inNode->SetForwardsConnection(conn);

    conn->SetBackwardsConnection(inNode);
    conn->SetForwardsConnection(outNode);
    
    outNode->SetBackwardsConnection(conn);

    inNode->CalculateActivation();
    inNode->printActivation();
    conn->printActivation();
    outNode->CalculateActivation();
    outNode->printActivation();
    */
    
    /*
    std::shared_ptr<InputLayer> inLayer = std::make_shared<InputLayer>(mnistImages);
    std::shared_ptr<HiddenLayer> hidLayer = std::make_shared<HiddenLayer>(16);
    std::shared_ptr<HiddenLayer> hidLayer2 = std::make_shared<HiddenLayer>(16);
    std::shared_ptr<OutputLayer> outLayer = std::make_shared<OutputLayer>(mnistLabels);
    *inLayer<<*hidLayer<<*hidLayer2<<*outLayer;
    inLayer->CalculateActivation();
    hidLayer->CalculateActivation();
    hidLayer2->CalculateActivation();
    outLayer->CalculateActivation();
    outLayer->PrintLayer();
    */
    
    
    std::vector<int> vec = {16, 16};
    Network neuralNet(mnistImages, vec, mnistLabels);
    neuralNet.PropogateForward();
    neuralNet.PropogateBackwards();
    neuralNet.PrintOutputLayer();
    

    //std::shared_ptr<Entity> ent = std::make_shared<InputNode>();
    std::cout << "Successful excecution!" << std::endl;
    return 0;
}