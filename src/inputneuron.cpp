#include "inputneuron.hpp"

InputNeuron::InputNeuron()
    : Neuron(nullptr)
{
}

InputNeuron::InputNeuron(double signal)
    : Neuron(nullptr)
{
    m_axon.setSignal(signal);
}

InputNeuron::~InputNeuron()
{
}

void InputNeuron::computeSignal()
{
    // STUB
}

void InputNeuron::setSignal(double signal)
{
    m_computedSignal= signal;
    m_axon.setSignal(signal);
}
