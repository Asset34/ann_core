#ifndef INPUTNEURON_HPP
#define INPUTNEURON_HPP

#include "neuron.hpp"

class InputNeuron : public Neuron
{
public:
    InputNeuron();
    InputNeuron(double signal);
    virtual ~InputNeuron();

    virtual void setSignal(double signal);
    virtual void computeSignal();

};

#endif // INPUTNEURON_HPP
