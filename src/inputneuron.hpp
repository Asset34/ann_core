#ifndef INPUTNEURON_HPP
#define INPUTNEURON_HPP

#include "neuron.hpp"

class InputNeuron : public Neuron
{
public:
    InputNeuron(double input = 0.0);
    virtual ~InputNeuron();

    virtual void setInput(double input);
    virtual void compute();

};

#endif // INPUTNEURON_HPP
