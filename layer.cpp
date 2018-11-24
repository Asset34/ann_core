#include "layer.hpp"

#include <algorithm>

Layer::Layer(size_t size, double bias)
    : m_neurons(size)
{
    for (size_t i = 0; i < m_neurons.size(); i++) {
        m_neurons[i] = new Neuron(bias);
    }
}

Layer::Layer(size_t size, const ActivationFunc &func, double bias)
    : m_neurons(size)
{
    for (size_t i = 0; i < m_neurons.size(); i++) {
        m_neurons[i] = new Neuron(func, bias);
    }
}

Layer::Layer(Layer &&other)
    : m_neurons(other.m_neurons)
{
    other.m_neurons.clear();
}
Layer &Layer::operator=(Layer &&other)
{
    for (int i = 0; i < m_neurons.size(); i++) {
        delete m_neurons[i];
    }

    m_neurons = other.m_neurons;
    other.m_neurons.clear();

    return *this;
}

void Layer::setActivationFunc(const ActivationFunc &func)
{
    for (Neuron *neuron : m_neurons) {
        neuron->setActivationFunc(func);
    }
}

void Layer::setActivationFuncs(const std::vector<ActivationFunc> &funcs)
{
    if (m_neurons.size() < funcs.size()) {
        return;
    }

    for (size_t i = 0; i < funcs.size(); i++) {
        m_neurons[i]->setActivationFunc(funcs[i]);
    }
}

void Layer::setBias(double bias)
{
    for (Neuron *neuron : m_neurons) {
        neuron->setBias(bias);
    }
}

void Layer::setBiases(const std::vector<double> biases)
{
    if (m_neurons.size() < biases.size()) {
        return;
    }

    for (size_t i = 0; i < biases.size(); i++) {
        m_neurons[i]->setBias(biases[i]);
    }
}

std::vector<double> Layer::getOutputs() const
{
    std::vector<double> vec(m_neurons.size());

    for (size_t i = 0; i < m_neurons.size(); i++) {
        vec[i] = m_neurons[i]->getOutput();
    }

    return vec;
}

void Layer::setWeights(const WeightMat &mat)
{
    if (m_neurons.size() < mat.size()) {
        return;
    }

    for (size_t i = 0; i < mat.size(); i++) {
        m_neurons[i]->setWeights(mat[i]);
    }
}

void Layer::connectAllToOne(Neuron &neuron, const WeightVec &vec)
{
    if (m_neurons.size() < vec.size()) {
        return;
    }

    // Connect with presented weights
    for (size_t i = 0; i < vec.size(); i++) {
        m_neurons[i]->connect(neuron, vec[i]);
    }

    // Connect rest neurons without weights
    for (size_t i = vec.size(); i < m_neurons.size(); i++) {
        m_neurons[i]->connect(neuron);
    }
}

void Layer::connectAllToAll(Layer &layer, const WeightMat &mat)
{
    if (layer.m_neurons.size() < mat.size()) {
        return;
    }

    // Connect with presented weights
    for (size_t i = 0; i < mat.size(); i++) {
        connectAllToOne(*layer.m_neurons[i], mat[i]);
    }

    // Connect rest neurons without weights
    for (size_t i = mat.size(); i < layer.m_neurons.size(); i++) {
        connectAllToOne(*layer.m_neurons[i]);
    }
}

void Layer::connectOneToOne(Layer &layer, const WeightVec &vec)
{
    if (m_neurons.size() != layer.m_neurons.size()) {
        return;
    }
    if (m_neurons.size() < vec.size()) {
        return;
    }

    // Connect with presented weights
    for (size_t i = 0; i < vec.size(); i++) {
        m_neurons[i]->connect(*layer.m_neurons[i], vec[i]);
    }

    // Connect rest neurons without weights
    for (size_t i = vec.size(); i < layer.m_neurons.size(); i++) {
        m_neurons[i]->connect(*layer.m_neurons[i]);
    }
}

void Layer::connectLoopback(const WeightMat &mat)
{
    connectAllToAll(*this, mat);
}

void Layer::compute()
{
    for (Neuron *neuron : m_neurons) {
        neuron->compute();
    }
}

void Layer::send()
{
    for (Neuron *neuron : m_neurons) {
        neuron->send();
    }
}

void Layer::move()
{
    compute();
    send();
}

void Layer::reset()
{
    for (Neuron *neuron : m_neurons) {
        neuron->reset();
    }
}
