#include "inputlayer.hpp"
#include "inputneuron.hpp"

InputLayer::InputLayer(size_t n)
{
    m_neurons.resize(n);

    for (size_t i = 0; i < n; i++) {
        m_neurons[i] = new InputNeuron;
    }
}

InputLayer::InputLayer(const WeightVec &vec)
{
    m_neurons.resize(vec.size());

    for (size_t i = 0; i < vec.size(); i++) {
        m_neurons[i] = new InputNeuron(vec[i]);
    }
}

void InputLayer::setInputs(const std::vector<double> &vec)
{
    for (size_t i = 0; i < m_neurons.size(); i++) {
        m_neurons[i]->setInput(vec[i]);
    }
}
