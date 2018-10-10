#ifndef LAYER_HPP
#define LAYER_HPP

#include <vector>

#include "transferfunc.hpp"
#include "neuron.hpp"
#include "matrix.hpp"

class Layer
{
public:
    Layer(int n, TransferFunc *tf);
    Layer(int n, TransferFunc *tf, double bias);
    virtual ~Layer();

    Neuron *getAt(int index);

    void setTransferFunc(TransferFunc *tf);
    void setBias(double bias);

    void setWeights(const Matrix &weights);
    Matrix getWeights() const;

    Vector getSignals() const;

    void connect(Neuron *neuron, const Vector &weights);
    void connect(Layer &layer, const Matrix &weights);
    void connect1to1(Layer &layer, const Vector &weights);

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
