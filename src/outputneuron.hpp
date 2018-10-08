#ifndef OUTPUTNEURON_HPP
#define OUTPUTNEURON_HPP

#include "neuron.hpp"

class OutputNeuron : public Neuron
{
public:
    virtual ~OutputNeuron();

    double getSignal() const;
};

#endif // OUTPUTNEURON_HPP
