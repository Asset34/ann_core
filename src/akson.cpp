#include "neuron.hpp"

void AbstractNeuron::Akson::setSignal(double signal)
{
    m_signal = signal;
}

double AbstractNeuron::Akson::getSignal() const
{
    return m_signal;
}
