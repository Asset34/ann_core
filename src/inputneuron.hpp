#ifndef INPUTNEURON_HPP
#define INPUTNEURON_HPP

#include "abstractneuron.hpp"
#include "neuron.hpp"

class InputNeuron : public AbstractNeuron
{
public:
    InputNeuron(double signal = 0.0);
    virtual ~InputNeuron();

    void setSignal(double signal);

    virtual void sendSignal();

private:
    double m_signal;

};

#endif // INPUTNEURON_HPP
