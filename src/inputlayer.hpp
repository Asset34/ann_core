#ifndef INPUTLAYER_HPP
#define INPUTLAYER_HPP

#include "layer.hpp"
#include "vector.hpp"
#include "inputneuron.hpp"

class InputLayer : public Layer
{
public:
    InputLayer(int n);
    virtual ~InputLayer();

    void setSignals(const Vector &siignals);

};

#endif // INPUTLAYER_HPP
