#include "outputneuron.hpp"

OutputNeuron::~OutputNeuron()
{
}

double OutputNeuron::getSignal() const
{
    return m_akson.getSignal();
}
