#ifndef NEURON_HPP
#define NEURON_HPP

#include <vector>

#include "transferfunc.hpp"
#include "vector.hpp"

class Neuron
{
public:
    Neuron(const TransferFunc *tf);
    Neuron(const TransferFunc *tf, double bias);
    virtual ~Neuron();

    void setTransferFunc(const TransferFunc *tf);
    const TransferFunc *getTransferFunc() const;

    void setBias(double bias);
    double getBias() const;

    void setWeights(const Vector &weights);
    Vector getWeights() const;

    int getSynapseCount() const;

    virtual void setSignal(double signal);
    double getSignal() const;

    void connect(Neuron &neuron, double weight);
    static void connect(Neuron &n1, Neuron &n2, double weight);

    virtual void computeSignal();
    void sendSignal();

protected:
    class Axon
    {
    public:
        Axon();

        void setSignal(double signal);
        double getSignal() const;

    private:
        double m_signal;

    };

    class Synapse
    {
    public:
        explicit Synapse(const Axon *axon);
        Synapse(const Axon *axon, double weight);

        void setWeight(double weight);
        double getWeight() const;

        double receiveSignal() const;
        double receiveWeightedSignal() const;

    private:
        const Axon *m_inputAxon;
        double m_weight;

    };

    std::vector<Synapse> m_inputSynapses;
    const TransferFunc *m_tf;
    double m_bias;
    Axon m_axon;

    double m_computedSignal;
};

#endif // NEURON_HPP
