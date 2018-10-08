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
}

Neuron::~Neuron()
{
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

void Neuron::sendSignal()
{
    // Compute sum
    double sum = 0.0;
    for (int i = 0; i < m_inputSynapses.size(); i++) {
        sum += m_inputSynapses[i].receiveWeightedSignal();
    }

    // Set output signal
    m_akson.setSignal(m_activationFunc->evaluate(sum) + m_bias);
}
