#include "layer.hpp"

Layer::Layer(int n, TransferFunc *tf)
    : m_neurons(n)
{
    for (int i = 0; i < n; i++) {
        m_neurons[i] = new Neuron(tf);
    }
}

Layer::Layer(int n, TransferFunc *tf, double bias)
    : m_neurons(n)
{
    for (int i = 0; i < n; i++) {
        m_neurons[i] = new Neuron(tf, bias);
    }
}

Layer::~Layer()
{
}

Neuron *Layer::getAt(int index)
{
    return m_neurons[index];
}

void Layer::setTransferFunc(TransferFunc *tf)
{
    for (int i = 0; i < m_neurons.size(); i++) {
        m_neurons[i]->setTransferFunc(tf);
    }
}

void Layer::setBias(double bias)
{
    for (int i = 0; i < m_neurons.size(); i++) {
        m_neurons[i]->setBias(bias);
    }
}

void Layer::setWeights(const Matrix &weights)
{
    for (int i = 0; i < m_neurons.size(); i++) {
        m_neurons[i]->setWeights(weights.getRowAt(i));
    }
}

Matrix Layer::getWeights() const
{
    Matrix weights(m_neurons.size(), getMaxSynapseCount());

    for (int i = 0; i < m_neurons.size(); i++) {
        weights.setRowAt(i, m_neurons[i]->getWeights());
    }

    return weights;
}

Vector Layer::getSignals() const
{
    Vector siignals(m_neurons.size());

    for (int i = 0; i < m_neurons.size(); i++) {
        siignals[i] = m_neurons[i]->getSignal();
    }

    return siignals;
}

void Layer::connect(Neuron *neuron, const Vector &weights)
{
    Vector resized = weights.resized(m_neurons.size());

    for (int i = 0; i < m_neurons.size(); i++) {
        m_neurons[i]->connect(*neuron, resized[i]);
    }
}

void Layer::connect(Layer &layer, const Matrix &weights)
{
    Matrix resized = weights.resized(layer.m_neurons.size(), m_neurons.size());

    for (int i = 0; i < layer.m_neurons.size(); i++) {
        connect(layer.m_neurons[i], resized.getRowAt(i));
    }
}

void Layer::connect1to1(Layer &layer, const Vector &weights)
{
    Vector resized = weights.resized(m_neurons.size());

    for (int i = 0; i < m_neurons.size(); i++) {
        m_neurons[i]->connect(*layer.m_neurons[i], resized[i]);
    }
}

void Layer::computeSignals()
{
    for (int i = 0; i < m_neurons.size(); i++) {
        m_neurons[i]->computeSignal();
    }
}

void Layer::sendSignals()
{
    for (int i = 0; i < m_neurons.size(); i++) {
        m_neurons[i]->sendSignal();
    }
}

void Layer::moveSignals()
{
    computeSignals();
    sendSignals();
}

Layer::Layer()
{
}

int Layer::getMaxSynapseCount() const
{
    int count = 0;

    for (int i = 0; i < m_neurons.size(); i++) {
        if (m_neurons[i]->getSynapseCount() > count) {
            count = m_neurons[i]->getSynapseCount();
        }
    }

    return count;
}
