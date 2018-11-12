#include "inputneuron.hpp"

InputNeuron::InputNeuron(double input)
    : Neuron()
{
    setInput(input);
}

InputNeuron::~InputNeuron()
{
}

void InputNeuron::setInput(double input)
{
    m_memory = input;
    m_output = input;
}

void InputNeuron::compute()
{
    // STUB
}
