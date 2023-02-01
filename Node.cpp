#include "Node.h"

//--------------
// Input Node
//--------------
float InputNode::activationFunction(float input)
{
    return input; //No activation function
}

float InputNode::activationFunctionDerivative(float input)
{
    return input; //No activation function derivative
}

float InputNode::activationInput()
{
    return 1.0f; // get from file
}

//--------------
// Hidden Node
//--------------
float HiddenNode::activationFunction(float input)
{
    return (input>0) ? input : 0; //ReLu
}

float HiddenNode::activationFunctionDerivative(float input)
{
    return (input>0) ? 1 : 0; //ReLu
}

//--------------
// Output Node
//--------------
float OutputNode::activationFunction(float input)
{
    return input; // needs someting special
}

float OutputNode::activationFunctionDerivative(float input)
{
    return input; // needs someting special
}