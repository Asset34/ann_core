#ifndef INPUTLAYER_HPP
#define INPUTLAYER_HPP

#include "entities.hpp"
#include "layer.hpp"

class InputLayer : public Layer
{
public:
    explicit InputLayer(size_t n);
    explicit InputLayer(const WeightVec &vec);
    InputLayer(const InputLayer &other) = delete;
    InputLayer(InputLayer &&other);

    InputLayer &operator=(const InputLayer &other) = delete;
    InputLayer &operator=(InputLayer &&other);

    void setInputs(const std::vector<double> &vec);

};

#endif // INPUTLAYER_HPP
