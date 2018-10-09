#ifndef INPUTLAYER_HPP
#define INPUTLAYER_HPP

#include "layer.hpp"
#include "vector.hpp"
#include "inputneuron.hpp"

class InputLayer : public Layer
{
public:
    InputLayer(int n);

    void setSignals(const Vector &signalVec);

};

#endif // INPUTLAYER_HPP
