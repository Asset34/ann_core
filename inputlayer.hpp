#ifndef INPUTLAYER_HPP
#define INPUTLAYER_HPP

#include "entities.hpp"
#include "layer.hpp"

class InputLayer : public Layer
{
public:
    explicit InputLayer(size_t n);
    explicit InputLayer(const WeightVec &vec);

    void setInputs(const std::vector<double> &vec);

};

#endif // INPUTLAYER_HPP
