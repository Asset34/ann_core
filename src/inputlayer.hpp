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
    Vector getSignals() const;

};

#endif // INPUTLAYER_HPP
