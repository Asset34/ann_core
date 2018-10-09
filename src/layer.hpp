#ifndef LAYER_HPP
#define LAYER_HPP

#include <vector>
#include <string>
#include <sstream>

#include "activationfunction.hpp"
#include "neuron.hpp"
#include "matrix.hpp"

class Layer
{
public:
    Layer(int n, ActivationFunction *func);
    Layer(int n, ActivationFunction *func, double bias);
    virtual ~Layer();

    void setActivationFunc(ActivationFunction *func);
    void setBias(double bias);

    Neuron *getAt(int index);

    void setWeights(const Matrix &weightMatrix);
    Matrix getWeights() const;

    Vector getSignals() const;

    void connectAll(Neuron *neuron, const Vector &weightVec);
    void connectAll(Layer &layer, const Matrix &weightMatrix);
    void connectOneByOne(Layer &layer, const Vector &weightVec);

    void computeSignals();
    void sendSignals();
    void moveSignals();

protected:
    Layer();

    std::vector<Neuron*> m_neurons;

private:
    int getMaxSynapseCount() const;

};

#endif // LAYER_HPP
