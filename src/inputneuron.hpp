#ifndef INPUTNEURON_HPP
#define INPUTNEURON_HPP

#include "neuron.hpp"

class InputNeuron : public Neuron
{
public:
    InputNeuron(double signal = 0.0);
    virtual ~InputNeuron();

    virtual void setSignal(double signal);
    virtual void sendSignal();

private:
    double m_signal;

};

#endif // INPUTNEURON_HPP
