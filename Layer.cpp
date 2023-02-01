#include "Layer.h"

LayerBase::LayerBase(int size) : layerSize(size)
{
}

template<typename T>
LayerTemplate<T>::LayerTemplate(int size) : LayerBase(size)
{
    //Allocate space for entities in layer
    layerEntity = new T[layerSize];

    //Construct all entities
    for (int i = 0; i < layerSize; i++)
    {
        layerEntity[i]();
    }

}

template<typename T>
LayerTemplate<T>::~LayerTemplate()
{

}
