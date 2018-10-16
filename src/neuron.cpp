#include "neuron.hpp"

Neuron::Neuron()
    : m_bias(0.0),
      m_memory(0.0)
{
    m_activationFunc =
        [](double x) -> double
        {
            return x;
        };
}

Neuron::Neuron(activation_func activationFunc,
               double bias)
    : m_activationFunc(activationFunc),
      m_bias(bias),
      m_memory(0.0)
{
}

Neuron::~Neuron()
{
}

int Neuron::getInputCount() const
{
    return m_inputs.size();
}

void Neuron::setWeights(const vec &weights)
{
    for (size_t i = 0; i < m_inputs.size(); i++) {
        m_inputs[i].setWeight(weights[i]);
    }
}

Neuron::vec Neuron::getWeights() const
{
    std::vector<double> weights(m_inputs.size());

    for (size_t i = 0; i < m_inputs.size(); i++) {
        weights[i] = m_inputs[i].getWeight();
    }

    return weights;
}

void Neuron::setActivationFunc(Neuron::activation_func activationFunc)
{
    m_activationFunc = activationFunc;
}

void Neuron::setBias(double bias)
{
    m_bias = bias;
}

double Neuron::getBias() const
{
    return m_bias;
}

void Neuron::setInput(double input)
{
    // STUB
}

double Neuron::getOutput() const
{
    return m_output;
}

void Neuron::connect(Neuron *neuron, double weight)
{
    Synapse synapse(this, weight);
    neuron->m_inputs.push_back(synapse);
}

void Neuron::compute()
{
    double sum = 0.0;
    for (size_t i = 0; i < m_inputs.size(); i++) {
        sum += m_inputs[i].recvWeighted();
    }

    m_memory = m_activationFunc(sum + m_bias);
}

void Neuron::send()
{
    m_output = m_memory;
}
