#include "inputneuron.hpp"

InputNeuron::InputNeuron()
    : Neuron(nullptr),
      m_signal(0.0)
{
}

InputNeuron::InputNeuron(double signal)
    : Neuron(nullptr),
      m_signal(signal)
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
