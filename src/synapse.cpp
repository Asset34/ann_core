#include "neuron.hpp"

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

double Neuron::Synapse::getWeightedSignal() const
{
    return m_inputAkson->getSignal() * m_weight;
}
