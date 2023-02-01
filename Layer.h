#pragma once
#include "Node.h"
#include "Connection.h"

class LayerBase
{
private:
    const int layerSize;
public:
    LayerBase(int size);
    ~LayerBase();
};

template<typename T>
class LayerTemplate : LayerBase
{
private:
    T* layerEntity;
public:
    LayerTemplate(int size);
    ~LayerTemplate();
};

typedef LayerTemplate<InputNode>  InputLayer;
typedef LayerTemplate<OutputNode> OutputLayer;
typedef LayerTemplate<HiddenNode> HiddenLayer;
typedef LayerTemplate<Connection> ConnectionLayer;