#ifndef LAYER_HPP
#define LAYER_HPP

#include "entities.hpp"
#include "neuron.hpp"

class Layer
{
public:
    Layer(size_t n, double bias = 0.0);
    Layer(size_t n,
          activation_func activationFunc,
          double bias = 0.0);
    virtual ~Layer();

    void setActivationFunc(activation_func activationFunc);
    void setBias(double bias);

    void setInputWeights(const mat &weights);
    mat getInputWeights() const;

    void setOutputWeights(const mat &weights);
    mat getOutputWeights() const;

    vec getOutputs() const;

    void connectAllToOne(Neuron *neuron, const vec &weights = vec());
    void connectAllToAll(Layer &layer, const mat &weights = mat());
    void connectOneToOne(Layer &layer, const vec &weights = vec());

    void compute();
    void send();
    void move();

protected:
    std::vector<Neuron*> m_neurons;

};

#endif // LAYER_HPP
