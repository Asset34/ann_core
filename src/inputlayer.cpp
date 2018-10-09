#include "inputlayer.hpp"

InputLayer::InputLayer(int n)
    : Layer(n, nullptr)
{
}

void InputLayer::setSignals(const Vector &signalVec)
{
    Vector resizedSignalVec = signalVec.resized(m_neurons.size());

    for (int i = 0; i < m_neurons.size(); i++) {
        m_neurons[i].setSignal(resizedSignalVec[i]);
    }
}

Vector InputLayer::getSignals() const
{
    Vector signalVec(m_neurons.size());

    for (int i = 0; i < m_neurons.size(); i++) {
        signalVec[i] = m_neurons[i].getSignal();
    }

    return signalVec;
}
