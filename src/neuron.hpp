#ifndef NEURON_HPP
#define NEURON_HPP

#include <vector>
#include <functional>

class Neuron
{
    typedef std::function<double(double)> activation_func;
    typedef std::vector<double> vec;

public:
    Neuron();
    Neuron(activation_func activationFunc,
           double bias = 0.0);
    virtual ~Neuron();

    int getInputCount() const;
    int getOutputCount() const;

    void setInputWeights(const vec &weights);
    vec getInputWeights() const;

    void setOutputWeights(const vec &weights);
    vec getOutputWeights() const;

    void setActivationFunc(activation_func activationFunc);

    void setBias(double bias);
    double getBias() const;

    virtual void setInput(double input);
    double getOutput() const;

    void connect(Neuron *neuron, double weight = 0.0);

    virtual void compute();
    void send();

protected:
    class Synapse
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

    std::vector<Synapse*> m_inputs;
    activation_func m_activationFunc;
    double m_bias;
    double m_output;
    std::vector<Synapse*> m_outputs;

    double m_memory;

};

#endif // NEURON_HPP
