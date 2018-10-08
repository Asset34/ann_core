#ifndef ABSTRACTNEURON_HPP
#define ABSTRACTNEURON_HPP

#include <vector>

class AbstractNeuron
{
public:
    virtual ~AbstractNeuron();

    double getOutputSignal() const;

    virtual void connect(AbstractNeuron *neuron, double weight);
    virtual void sendSignal() = 0;

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

};

#endif // ABSTRACTNEURON_HPP
