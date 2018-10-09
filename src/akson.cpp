#include "neuron.hpp"

Neuron::Akson::Akson()
    : m_signal(0.0)
{
}

void Neuron::Akson::setSignal(double signal)
{
    m_signal = signal;
}

double Neuron::Akson::getSignal() const
{
    return m_signal;
}
