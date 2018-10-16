#include "neuron.hpp"

Neuron::Synapse::Synapse(const Neuron *neuron,
                         double weight)
    : m_neuron(neuron),
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

double Neuron::Synapse::recv() const
{
    return m_neuron->getOutput();
}

double Neuron::Synapse::recvWeighted() const
{
    return m_neuron->getOutput() * m_weight;
}
