#ifndef NEURON_HPP
#define NEURON_HPP

#include <vector>

#include "activationfunction.hpp"

class Neuron
{
public:
    Neuron(double bias = 0.0);
    Neuron(ActivationFunction *func, double bias = 0.0);
    virtual ~Neuron();

    void setActivationFunc(ActivationFunction *func);
    ActivationFunction *getActivationFunc() const;

    void setBias(double bias);
    double getBias() const;

    double getSignal() const;

    void connect(Neuron *neuron, double weight);
    static void connect(Neuron *n1, Neuron *n2, double weight);

    virtual void sendSignal();

protected:
    class Akson
    {
    public:
        void setSignal(double signal);
        double getSignal() const;

    private:
        double m_signal = 0.0;

    };

    class Synapse
    {
    public:
        explicit Synapse(const Akson *akson, double weight = 1.0);

        void setWeight(double weight);
        double getWeight() const;

        double receiveSignal() const;
        double receiveWeightedSignal() const;

    private:
        const Akson *m_inputAkson;
        double m_weight;

    };

    Akson m_akson;
    std::vector<Synapse> m_inputSynapses;

    ActivationFunction *m_activationFunc;
    double m_bias;
};

#endif // NEURON_HPP
