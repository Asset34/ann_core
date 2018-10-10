#include "neuron.hpp"

Neuron::Axon::Axon()
    : m_signal(0.0)
{
}

void Neuron::Axon::setSignal(double signal)
{
    m_signal = signal;
}

double Neuron::Axon::getSignal() const
{
    return m_signal;
}
