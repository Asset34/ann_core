#ifndef INPUTLAYER_HPP
#define INPUTLAYER_HPP

#include "layer.hpp"

class InputLayer : public Layer
{
    typedef std::vector<double> vec;

public:
    InputLayer(size_t n);
    InputLayer(const vec &inputs);
    virtual ~InputLayer();

    void setInputs(const vec &inputs);

};

#endif // INPUTLAYER_HPP
