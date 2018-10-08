#include "neuron.hpp"

AbstractNeuron::Synapse::Synapse(const Akson *akson, double weight)
    : m_inputAkson(akson),
      m_weight(weight)
{
}

void AbstractNeuron::Synapse::setWeight(double weight)
{
    m_weight = weight;
}

double AbstractNeuron::Synapse::getWeight() const
{
    return m_weight;
}

double AbstractNeuron::Synapse::receiveSignal() const
{
    return m_inputAkson->getSignal();
}

double AbstractNeuron::Synapse::receiveWeightedSignal() const
{
    return m_inputAkson->getSignal() * m_weight;
}
