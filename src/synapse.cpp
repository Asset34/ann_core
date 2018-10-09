#include "neuron.hpp"

Neuron::Synapse::Synapse(const Neuron::Akson *akson)
    : m_inputAkson(akson),
      m_weight(weight)
{
}

Neuron::Synapse::Synapse(const Akson *akson, double weight)
    : m_inputAkson(akson),
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
    return m_inputAkson->getSignal();
}

double Neuron::Synapse::receiveWeightedSignal() const
{
    return m_inputAkson->getSignal() * m_weight;
}
