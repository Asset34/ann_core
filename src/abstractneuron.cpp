#include "abstractneuron.hpp"

AbstractNeuron::~AbstractNeuron()
{
}

double AbstractNeuron::getSignal() const
{
    return m_akson.getSignal();
}
