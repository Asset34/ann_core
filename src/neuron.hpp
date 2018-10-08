#ifndef NEURON_HPP
#define NEURON_HPP

#include <vector>

#include "activationfunction.hpp"
#include "abstractneuron.hpp"

class Neuron : public AbstractNeuron
{
public:
    Neuron(double bias = 0.0);
    Neuron(ActivationFunction *func, double bias = 0.0);
    virtual ~Neuron();

    void setActivationFunc(ActivationFunction *func);
    ActivationFunction *getActivationFunc() const;

    void setBias(double bias);
    double getBias() const;

    virtual void sendSignal();

private:

    ActivationFunction *m_activationFunc;
    double m_bias;
};

#endif // NEURON_HPP
