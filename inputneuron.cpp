#include "inputneuron.hpp"

InputNeuron::InputNeuron(double input)
{
    setInput(input);
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

void InputNeuron::reset()
{
    // STUB
}
