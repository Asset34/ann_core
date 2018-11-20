#ifndef LAYER_HPP
#define LAYER_HPP

#include <vector>

#include "entities.hpp"
#include "neuron.hpp"

class Layer
{
public:
    explicit Layer(size_t size, double bias = 0.0);
    Layer(size_t size, const ActivationFunc &func, double bias = 0.0);
    virtual ~Layer();

    void setActivationFunc(const ActivationFunc &func);
    void setActivationFuncs(const std::vector<ActivationFunc> &funcs);

    void setBias(double bias);
    void setBiases(const std::vector<double> biases);

    std::vector<double> getOutputs() const;

    WeightMat getWeights() const;
    void setWeights(const WeightMat &mat);

    void connectAllToOne(Neuron &neuron, const WeightVec &vec = WeightVec());
    void connectAllToAll(Layer &layer, const WeightMat &mat = WeightMat());
    void connectOneToOne(Layer &layer, const WeightVec &vec = WeightVec());

    void compute();
    void send();
    void move();

    void reset();

protected:
    Layer() = default;

    std::vector<Neuron*> m_neurons;

};

#endif // LAYER_HPP
