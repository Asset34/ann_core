#include "neuron.hpp"

Neuron::Synapse::Synapse(const Neuron::Axon *axon)
    : m_inputAxon(axon),
      m_weight(1.0)
{
}

Neuron::Synapse::Synapse(const Axon *axon, double weight)
    : m_inputAxon(axon),
      m_weight(weight)
{
}

void Neuron::Synapse::setWeight(double weight)
{
    m_weight = weight;
}

double Neuron::Synapse::getWeight() const
{
    return m_weight;
}

double Neuron::Synapse::receiveSignal() const
{
    return m_inputAxon->getSignal();
}

double Neuron::Synapse::receiveWeightedSignal() const
{
    return m_inputAxon->getSignal() * m_weight;
}
