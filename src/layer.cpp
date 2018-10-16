#include "layer.hpp"

#include <algorithm>

Layer::Layer(size_t n)
    : m_neurons(n)
{
    for (size_t i = 0; i < n; i++) {
        m_neurons[i] = new Neuron();
    }
}

Layer::Layer(size_t n,
             activation_func activationFunc,
             double bias)
    : m_neurons(n)
{
    for (size_t i = 0; i < n; i++) {
        m_neurons[i] = new Neuron(activationFunc, bias);
    }
}

Layer::~Layer()
{
    for (size_t i = 0; i < m_neurons.size(); i++) {
        delete m_neurons[i];
    }
}

Neuron *Layer::getAt(int index)
{
    return m_neurons[index];
}

void Layer::setActivationFunc(activation_func activationFunc)
{
    for (size_t i = 0; i < m_neurons.size(); i++) {
        m_neurons[i]->setActivationFunc(activationFunc);
    }
}

void Layer::setBias(double bias)
{
    for (size_t i = 0; i < m_neurons.size(); i++) {
        m_neurons[i]->setBias(bias);
    }
}

void Layer::setInputWeights(const mat &weights)
{
    for (size_t i = 0; i < m_neurons.size(); i++) {
        m_neurons[i]->setInputWeights(weights[i]);
    }
}

mat Layer::getInputWeights() const
{
    mat weights(m_neurons.size());

    for (size_t i = 0; i < m_neurons.size(); i++) {
        weights[i] = m_neurons[i]->getInputWeights();
    }

    return weights;
}

void Layer::setOutputWeights(const mat &weights)
{
    for (size_t i = 0; i < m_neurons.size(); i++) {
        m_neurons[i]->setOutputWeights(weights[i]);
    }
}

mat Layer::getOutputWeights() const
{
    mat weights(m_neurons.size());

    for (size_t i = 0; i < m_neurons.size(); i++) {
        weights[i] = m_neurons[i]->getOutputWeights();
    }

    return weights;
}

vec Layer::getOutputs() const
{
    vec outputs(m_neurons.size());

    for (size_t i = 0; i < m_neurons.size(); i++) {
        outputs[i] = m_neurons[i]->getOutput();
    }

    return outputs;
}

void Layer::connectAllToOne(Neuron *neuron, const vec &weights)
{
    for (size_t i = 0; i < m_neurons.size(); i++) {
        m_neurons[i]->connect(neuron, weights[i]);
    }
}

void Layer::connectAllToAll(Layer &layer, const mat &weights)
{
    for (size_t i = 0; i < layer.m_neurons.size(); i++) {
        connectAllToOne(layer.m_neurons[i], weights[i]);
    }
}

void Layer::connectOneToOne(Layer &layer, const vec &weights)
{
    size_t size = std::min(m_neurons.size(), layer.m_neurons.size());

    for (size_t i = 0; i < size; i++) {
        m_neurons[i]->connect(layer.m_neurons[i], weights[i]);
    }
}

void Layer::compute()
{
    for (size_t i = 0; i < m_neurons.size(); i++) {
        m_neurons[i]->compute();
    }
}

void Layer::send()
{
    for (size_t i = 0; i < m_neurons.size(); i++) {
        m_neurons[i]->send();
    }
}

void Layer::move()
{
    compute();
    send();
}
