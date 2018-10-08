#include "neuron.hpp"

void Neuron::Akson::setSignal(double signal)
{
    m_signal = signal;
}

double Neuron::Akson::getSignal() const
{
    return m_signal;
}
