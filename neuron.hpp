#ifndef NEURON_HPP
#define NEURON_HPP

#include "entities.hpp"

class Neuron
{
public:
    explicit Neuron(double bias = 0.0);
    explicit Neuron(const ActivationFunc &func, double bias = 0.0);
    virtual ~Neuron() = default;

    void setActivationFunc(const ActivationFunc &func);

    void setBias(double bias);
    double getBias() const;

    virtual void setInput(double input);
    double getOutput() const;

    int getSynapseCount() const;

    WeightVec getWeights() const;
    void setWeights(const WeightVec &vec);

    void connect(Neuron &neuron, double weight = 0.0);

    virtual void compute();
    void send();

    virtual void reset();

protected:
    class Synapse;

    std::vector<Synapse> m_synapses;

    ActivationFunc m_activationFunc;

    double m_bias;

    double m_memory;
    double m_output;

};

class Neuron::Synapse
{
public:
    explicit Synapse(const Neuron *neuron,
                     double weight = 0.0);

    void setWeight(double weight);
    double getWeight() const;

    double recv() const;
    double recvWeighted() const;

private:
    const Neuron *m_neuron;
    double m_weight;

};

#endif // NEURON_HPP
