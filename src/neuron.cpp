#include "neuron.hpp"

Neuron::Neuron(const TransferFunc *tf)
    : m_tf(tf),
      m_bias(0.0),
      m_computedSignal(0.0)
{
}

Neuron::Neuron(const TransferFunc *tf, double bias)
    : m_tf(tf),
      m_bias(bias),
      m_computedSignal(0.0)
{
}

Neuron::~Neuron()
{
}

void Neuron::setTransferFunc(const TransferFunc *tf)
{
    m_tf = tf;
}

const TransferFunc *Neuron::getTransferFunc() const
{
    return m_tf;
}

void Neuron::setBias(double bias)
{
    m_bias = bias;
}

#include <Qvector>

double Neuron::getBias() const
{
    return m_bias;
}

void Neuron::setWeights(const Vector &weights)
{
    for (int i = 0; i < m_inputSynapses.size(); i++) {
        m_inputSynapses[i].setWeight(weights[i]);
    }
}

Vector Neuron::getWeights() const
{
    Vector weights(m_inputSynapses.size());

    for (int i = 0; i < m_inputSynapses.size(); i++) {
        weights[i] = m_inputSynapses[i].getWeight();
    }

    return weights;
}

int Neuron::getSynapseCount() const
{
    return m_inputSynapses.size();
}

void Neuron::setSignal(double signal)
{
    // STUB
}

double Neuron::getSignal() const
{
    return m_axon.getSignal();
}

void Neuron::connect(Neuron &neuron, double weight)
{
    Synapse synapse(&m_axon, weight);
    neuron.m_inputSynapses.push_back(synapse);
}

void Neuron::connect(Neuron &n1, Neuron &n2, double weight)
{
    n1.connect(n2, weight);
}

void Neuron::computeSignal()
{
    // Compute sum
    double sum = 0.0;
    for (int i = 0; i < m_inputSynapses.size(); i++) {
        sum += m_inputSynapses[i].receiveWeightedSignal();
    }

    m_computedSignal = m_tf->evaluate(sum) + m_bias;
}

void Neuron::sendSignal()
{
    m_axon.setSignal(m_computedSignal);
}
