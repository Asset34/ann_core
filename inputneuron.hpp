#ifndef INPUTNEURON_HPP
#define INPUTNEURON_HPP

#include "neuron.hpp"

class InputNeuron : public Neuron
{
public:
    InputNeuron(double input = 0.0);

    virtual void setInput(double input) override;
    virtual void compute() override;

};

#endif // INPUTNEURON_HPP
