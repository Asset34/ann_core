#include "layer.hpp"

Layer::Layer(int n, ActivationFunction *func)
    : m_neurons(n, Neuron(func))
{
}

Layer::Layer(int n, ActivationFunction *func, double bias)
    : m_neurons(n, Neuron(func, bias))
{
}

Layer::~Layer()
{
}

void Layer::setActivationFunc(ActivationFunction *func)
{
    for (int i = 0; i < m_neurons.size(); i++) {
        m_neurons[i].setActivationFunc(func);
    }
}

void Layer::setBias(double bias)
{
    for (int i = 0; i < m_neurons.size(); i++) {
        m_neurons[i].setBias(bias);
    }
}

Neuron &Layer::getAt(int index)
{
    return m_neurons[index];
}

void Layer::setWeights(const Matrix &weightMatrix)
{
    for (int i = 0; i < m_neurons.size(); i++) {
        m_neurons[i].setWeights(weightMatrix.getRowAt(i));
    }
}

Matrix Layer::getWeights() const
{
    Matrix weightMatrix(m_neurons.size(), getMaxSynapseCount());

    for (int i = 0; i < m_neurons.size(); i++) {
        weightMatrix.setRowAt(i, m_neurons[i].getWeights());
    }
}

void Layer::connectAll(Neuron &neuron, const Vector &weightVec)
{
    Vector resizedWeightVec = weightVec.resized(m_neurons.size());

    for (int i = 0; i < m_neurons.size(); i++) {
        m_neurons[i].connect(neuron, resizedWeightVec[i]);
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
        m_neurons[i].connect(layer.m_neurons[i], resizedWeightVec[i]);
    }
}

void Layer::sendSignal()
{
    for (int i = 0; i < m_neurons.size(); i++) {
        m_neurons[i].sendSignal();
    }
}

std::string Layer::getString() const
{
    std::stringstream ss;

    for (int i = 0; i < m_neurons.size(); i++) {
        ss << m_neurons[i].getSignal() << " ";
    }

    ss.str();
}

int Layer::getMaxSynapseCount() const
{
    int count = 0;

    for (int i = 0; i < m_neurons.size(); i++) {
        if (m_neurons[i].getSynapseCount() > count) {
            count = m_neurons[i].getSynapseCount();
        }
    }

    return count;
}
