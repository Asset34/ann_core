#ifndef INPUTLAYER_HPP
#define INPUTLAYER_HPP

#include "entities.hpp"
#include "layer.hpp"

class InputLayer : public Layer
{
public:
    InputLayer(size_t n);
    InputLayer(const vec &inputs);
    virtual ~InputLayer();

    void setInputs(const vec &inputs);

};

#endif // INPUTLAYER_HPP
