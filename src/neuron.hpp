#ifndef NEURON_HPP
#define NEURON_HPP

#include <vector>

#include "activationfunction.hpp"

class Neuron
{
public:
    Neuron(double bias = 0.0);
    Neuron(ActivationFunction *func, double bias = 0.0);
    ~Neuron();

    void connect(Neuron *neuron, double weight);
    void sendSignal();

    void setActivationFunc(ActivationFunction *func);
    ActivationFunction *getActivationFunc() const;

    void setBias(double bias);
    double getBias() const;

private:
    class Akson;
    class Synapse;

    Akson *m_akson;
    std::vector<Synapse> m_inputSynapses;

    ActivationFunction *m_activationFunc;
    double m_bias = 0.0;
};



class Neuron::Akson
{
public:
    void setSignal(double signal);
    double getSignal() const;

private:
    double m_signal = 0.0;

};



class Neuron::Synapse
{
public:
    explicit Synapse(const Akson *akson, double weight = 1.0);

    void setWeight(double weight);
    double getWeight() const;

    double getWeightedSignal() const;

private:
    const Akson *m_inputAkson;
    double m_weight = 1.0;

};

#endif // NEURON_HPP
