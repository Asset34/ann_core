#include "inputlayer.hpp"

InputLayer::InputLayer(int n)
{
    m_neurons.resize(n);

    for (int i = 0; i < n; i++) {
        m_neurons[i] = new InputNeuron;
    }
}

void InputLayer::setSignals(const Vector &siignals)
{
    Vector resized = siignals.resized(m_neurons.size());

    for (int i = 0; i < m_neurons.size(); i++) {
        m_neurons[i]->setSignal(resized[i]);
    }
}
