#include "neuron.hpp"

Neuron::Neuron(double bias)
    : m_bias(bias)
{
    // TODO: Set default activation fucntion
}

Neuron::Neuron(ActivationFunction *func, double bias)
    : m_activationFunc(func),
      m_bias(bias)
{
    m_akson = new Akson;
}

Neuron::~Neuron()
{
    delete m_akson;
}

void Neuron::connect(Neuron *neuron, double weight = 1.0)
{
    Synapse synapse(m_akson, weight);

    neuron->m_inputSynapses.push_back(synapse);
}

void Neuron::sendSignal()
{
    // Compute sum
    double sum = 0.0;
    for (int i = 0; i < m_inputSynapses.size(); i++) {
        sum += m_inputSynapses[i].getWeightedSignal();
    }

    // Set output signal
    m_akson->setSignal(m_activationFunc->evaluate(sum) + m_bias);
}

void Neuron::setActivationFunc(ActivationFunction *func)
{
    m_activationFunc = func;
}

ActivationFunction *Neuron::getActivationFunc() const
{
    return m_activationFunc;
}

void Neuron::setBias(double bias)
{
    m_bias = bias;
}

double Neuron::getBias() const
{
    return m_bias;
}
