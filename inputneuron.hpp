#ifndef INPUTNEURON_HPP
#define INPUTNEURON_HPP

#include "neuron.hpp"

class InputNeuron : public Neuron
{
public:
    explicit InputNeuron(double input = 0.0);

    virtual void setInput(double input) override;
    virtual void compute() override;
    virtual void reset() override;

};

#endif // INPUTNEURON_HPP
