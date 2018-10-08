#include "inputneuron.hpp"

InputNeuron::InputNeuron(double signal)
    : m_signal(signal)
{
}

InputNeuron::~InputNeuron()
{
}

void InputNeuron::sendSignal()
{
    m_akson.setSignal(m_signal);
}

void InputNeuron::setSignal(double signal)
{
    m_signal = signal;
}
