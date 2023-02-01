#include "Network.h"

Network::Network(mnistReader images, mnistReader labels, const int sizeHL1, const int sizeHL2)
{
    // Create 7 layers
    layers = new LayerBase[7];

    // Create input layer
    layers[0] = new inputLayer(mnistReader);
    layers[2] = new hiddenLayer(sizeHL1);
    layers[4] = new hiddenLayer(sizeHL2);
    layers[6] = new outputLayer(10);
    
    layers[1] = new ConnectionLayer(layers[0], layers[2]);
    layers[3] = new ConnectionLayer(layers[2], layers[4]);
    layers[5] = new ConnectionLayer(layers[4], layers[6]);

}

Network::~Network()
{
}