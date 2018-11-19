#include "neuron.hpp"

Neuron::Neuron(double bias)
    : m_bias(bias),
      m_memory(0.0),
      m_output(0.0)
{
    m_activationFunc =
        [](double x) -> double
        {
            return x;
        };
}

Neuron::Neuron(const ActivationFunc &func, double bias)
    : m_activationFunc(func),
      m_bias(bias),
      m_memory(0.0),
      m_output(0.0)
{
}

void Neuron::setActivationFunc(const ActivationFunc &func)
{
    m_activationFunc = func;
}

void Neuron::setBias(double bias)
{
    m_bias = bias;
}

double Neuron::getBias() const
{
    return m_bias;
}

void Neuron::setInput(double /*input*/)
{
    // STUB
}

double Neuron::getOutput() const
{
    return m_output;
}

int Neuron::getSynapseCount() const
{
    return m_synapses.size();
}

WeightVec Neuron::getWeights() const
{
    WeightVec vec(m_synapses.size());

    for (size_t i = 0; i < vec.size(); i++) {
        vec[i] = m_synapses[i].getWeight();
    }

    return vec;
}

void Neuron::setWeights(const WeightVec &vec)
{
    if (m_synapses.size() < vec.size()) {
        return;
    }

    for (size_t i = 0; i < vec.size(); i++) {
        m_synapses[i].setWeight(vec[i]);
    }
}

void Neuron::connect(Neuron &neuron, double weight)
{
    neuron.m_synapses.push_back(Synapse(this, weight));
}

void Neuron::compute()
{
    double sum = 0.0;
    for (Synapse synapse : m_synapses) {
        sum += synapse.recvWeighted();
    }

    m_memory = m_activationFunc(sum + m_bias);
}

void Neuron::send()
{
    m_output = m_memory;
}

void Neuron::reset()
{
    m_output = 0.0;
    m_memory = 0.0;
}
