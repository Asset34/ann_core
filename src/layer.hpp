#ifndef LAYER_HPP
#define LAYER_HPP

#include <vector>

#include "neuron.hpp"

class Layer
{
    typedef std::function<double(double)> activation_func;
    typedef std::vector<double> vec;
    typedef std::vector<std::vector<double>> mat;

public:
    Layer(size_t n);
    Layer(size_t n,
          activation_func activationFunc,
          double bias = 0.0);
    virtual ~Layer();

    Neuron *getAt(int index);

    void setActivationFunc(activation_func activationFunc);
    void setBias(double bias);

    void setWeights(const mat &weights);
    mat getWeights() const;

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
