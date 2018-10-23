#include "neuron.hpp"

Neuron::Neuron(double bias)
    : m_bias(bias),
      m_memory(0.0)
{
    m_activationFunc =
        [](double x) -> double
        {
            return x;
        };
}

Neuron::Neuron(activation_func func, double bias)
    : m_activationFunc(func),
      m_bias(bias),
      m_memory(0.0)
{
}

Neuron::~Neuron()
{
    for (size_t i = 0; i < m_outputs.size(); i++) {
        delete m_outputs[i];
    }
}

int Neuron::getInputCount() const
{
    return m_inputs.size();
}

int Neuron::getOutputCount() const
{
    return m_outputs.size();
}

void Neuron::setOutputWeights(const vec &weights)
{
    for (size_t i = 0; i < m_outputs.size(); i++) {
        m_outputs[i]->setWeight(weights[i]);
    }
}

vec Neuron::getOutputWeights() const
{
    vec weights(m_outputs.size());

    for (size_t i = 0; i < m_outputs.size(); i++) {
        weights[i] = m_outputs[i]->getWeight();
    }

    return weights;
}

void Neuron::setInputWeights(const vec &weights)
{
    for (size_t i = 0; i < m_inputs.size(); i++) {
        m_inputs[i]->setWeight(weights[i]);
    }
}

vec Neuron::getInputWeights() const
{
    vec weights(m_inputs.size());

    for (size_t i = 0; i < m_inputs.size(); i++) {
        weights[i] = m_inputs[i]->getWeight();
    }

    return weights;
}

void Neuron::setActivationFunc(activation_func func)
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
    Synapse *synapse = new Synapse(this, weight);

    m_outputs.push_back(synapse);
    neuron->m_inputs.push_back(synapse);
}

void Neuron::compute()
{
    double sum = 0.0;
    for (size_t i = 0; i < m_inputs.size(); i++) {
        sum += m_inputs[i]->recvWeighted();
    }

    m_memory = m_activationFunc(sum + m_bias);
}

void Neuron::send()
{
    m_output = m_memory;
}
