#include "neuron.hpp"

Neuron::Neuron(ActivationFunction *func)
    : m_activationFunc(func),
      m_bias(0.0)
{
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

void Neuron::setWeights(const Vector &weightVec)
{
    Vector resizedWeightVec = weightVec.resized(m_inputSynapses.size());

    for (int i = 0; i < m_inputSynapses.size(); i++) {
        m_inputSynapses[i].setWeight(resizedWeightVec[i]);
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

void Neuron::setSignal(double signal)
{
    // STUB
}

double Neuron::getSignal() const
{
    return m_akson.getSignal();
}

void Neuron::connect(Neuron *neuron, double weight)
{
    Synapse synapse(&m_akson, weight);
    neuron->m_inputSynapses.push_back(synapse);
}

void Neuron::connect(Neuron *n1, Neuron *n2, double weight)
{
    n1->connect(n2, weight);
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
