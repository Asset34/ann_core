#include "abstractneuron.hpp"

AbstractNeuron::~AbstractNeuron()
{
}

double AbstractNeuron::getOutputSignal() const
{
    return m_akson.getSignal();
}

void AbstractNeuron::connect(AbstractNeuron *neuron, double weight)
{
    Synapse synapse(&m_akson, weight);
    neuron->m_inputSynapses.push_back(synapse);
}
