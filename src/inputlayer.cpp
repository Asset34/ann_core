#include "inputlayer.hpp"
#include "inputneuron.hpp"

InputLayer::InputLayer(int n)
{
    m_neurons.resize(n);

    for (int i = 0; i < n; i++) {
        m_neurons[i] = new InputNeuron;
    }
}

InputLayer::~InputLayer()
{
}

void InputLayer::setSignals(const Vector &siignals)
{
    for (int i = 0; i < m_neurons.size(); i++) {
        m_neurons[i]->setSignal(siignals[i]);
    }
}
