#include "layer.hpp"

Layer::Layer(int n, ActivationFunction *func)
    : m_neurons(n)
{
    for (int i = 0; i < n; i++) {
        m_neurons[i] = new Neuron(func);
    }
}

Layer::Layer(int n, ActivationFunction *func, double bias)
    : m_neurons(n)
{
    for (int i = 0; i < n; i++) {
        m_neurons[i] = new Neuron(func, bias);
    }
}

Layer::~Layer()
{
}

void Layer::setActivationFunc(ActivationFunction *func)
{
    for (int i = 0; i < m_neurons.size(); i++) {
        m_neurons[i]->setActivationFunc(func);
    }
}

void Layer::setBias(double bias)
{
    for (int i = 0; i < m_neurons.size(); i++) {
        m_neurons[i]->setBias(bias);
    }
}

Neuron *Layer::getAt(int index)
{
    return m_neurons[index];
}

void Layer::setWeights(const Matrix &weightMatrix)
{
    for (int i = 0; i < m_neurons.size(); i++) {
        m_neurons[i]->setWeights(weightMatrix.getRowAt(i));
    }
}

Matrix Layer::getWeights() const
{
    Matrix weightMatrix(m_neurons.size(), getMaxSynapseCount());

    for (int i = 0; i < m_neurons.size(); i++) {
        weightMatrix.setRowAt(i, m_neurons[i]->getWeights());
    }
}

Vector Layer::getSignals() const
{
    Vector signalVec(m_neurons.size());

    for (int i = 0; i < m_neurons.size(); i++) {
        signalVec[i] = m_neurons[i]->getSignal();
    }

    return signalVec;
}

void Layer::connectAll(Neuron *neuron, const Vector &weightVec)
{
    Vector resizedWeightVec = weightVec.resized(m_neurons.size());

    for (int i = 0; i < m_neurons.size(); i++) {
        m_neurons[i]->connect(*neuron, resizedWeightVec[i]);
    }
}

void Layer::connectAll(Layer &layer, const Matrix &weightMatrix)
{
    Matrix resizedWeightMatrix = weightMatrix.resized(layer.m_neurons.size(), m_neurons.size());

    for (int i = 0; i < layer.m_neurons.size(); i++) {
        connectAll(layer.m_neurons[i], resizedWeightMatrix.getRowAt(i));
    }
}

void Layer::connectOneByOne(Layer &layer, const Vector &weightVec)
{
    Vector resizedWeightVec = weightVec.resized(m_neurons.size());

    for (int i = 0; i < m_neurons.size(); i++) {
        m_neurons[i]->connect(*layer.m_neurons[i], resizedWeightVec[i]);
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
