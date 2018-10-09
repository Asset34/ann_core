#ifndef NEURON_HPP
#define NEURON_HPP

#include <vector>

#include "activationfunction.hpp"
#include "vector.hpp"

class Neuron
{
public:
    Neuron(ActivationFunction *func);
    Neuron(ActivationFunction *func, double bias);
    virtual ~Neuron();

    void setActivationFunc(ActivationFunction *func);
    ActivationFunction *getActivationFunc() const;

    void setBias(double bias);
    double getBias() const;

    void setWeights(const Vector &weightVec);
    Vector getWeights() const;

    int getSynapseCount() const;

    virtual void setSignal(double signal);
    double getSignal() const;

    void connect(Neuron &neuron, double weight);
    static void connect(Neuron &n1, Neuron &n2, double weight);

    virtual void computeSignal();
    void sendSignal();

protected:
    class Akson
    {
    public:
        Akson();

        void setSignal(double signal);
        double getSignal() const;

    private:
        double m_signal;

    };

    class Synapse
    {
    public:
        explicit Synapse(const Akson *akson);
        Synapse(const Akson *akson, double weight);

        void setWeight(double weight);
        double getWeight() const;

        double receiveSignal() const;
        double receiveWeightedSignal() const;

    private:
        const Akson *m_inputAkson;
        double m_weight;

    };

    std::vector<Synapse> m_inputSynapses;
    ActivationFunction *m_activationFunc;
    double m_bias;
    Akson m_akson;

    double m_resultSignal;
};

#endif // NEURON_HPP
