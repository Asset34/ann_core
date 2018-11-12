#include "inputlayer.hpp"
#include "inputneuron.hpp"

InputLayer::InputLayer(size_t n)
    : Layer(0)
{
    m_neurons.resize(n);

    for (size_t i = 0; i < n; i++) {
        m_neurons[i] = new InputNeuron;
    }
}

InputLayer::InputLayer(const vec &inputs)
    : Layer(0)
{
    m_neurons.resize(inputs.size());

    for (size_t i = 0; i < inputs.size(); i++) {
        m_neurons[i] = new InputNeuron(inputs[i]);
    }
}

InputLayer::~InputLayer()
{
}

void InputLayer::setInputs(const vec &inputs)
{
    for (size_t i = 0; i < m_neurons.size(); i++) {
        m_neurons[i]->setInput(inputs[i]);
    }
}
