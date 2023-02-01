#include <iostream>
#include "mnistReader.h"
//#include "Network.h"
#include "Node.h"
#include "Connection.h"

int main()
{
    mnistReader mnistImages("./data/train-images-idx3.ubyte");
    mnistReader mnistLabels("./data/train-labels-idx1.ubyte");
    
    InputNode inNode = InputNode();
    OutputNode outNode = OutputNode();
    Connection conn = Connection();

    inNode << conn << outNode;

    inNode.CalculateActivation();
    inNode.printActivation();
    conn.printActivation();
    outNode.CalculateActivation();
    outNode.printActivation();
    //Network neuralNet(mnistImages, mnistLabels, 16, 16);
    return 0;
}