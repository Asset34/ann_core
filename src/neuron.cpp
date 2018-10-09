#include "neuron.hpp"

Neuron::Neuron(ActivationFunction *func)
    : m_activationFunc(func),
      m_bias(0.0),
      m_resultSignal(0.0)
{
}

Neuron::Neuron(ActivationFunction *func, double bias)
    : m_activationFunc(func),
      m_bias(bias),
      m_resultSignal(0.0)
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
    return m_akson.getSignal();
}

void Neuron::connect(Neuron &neuron, double weight)
{
    Synapse synapse(&m_akson, weight);
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

    m_resultSignal = m_activationFunc->evaluate(sum) + m_bias;
}

void Neuron::sendSignal()
{
    m_akson.setSignal(m_resultSignal);
}
