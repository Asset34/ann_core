#ifndef ABSTRACTNEURON_HPP
#define ABSTRACTNEURON_HPP

class AbstractNeuron
{
public:
    virtual ~AbstractNeuron();

//    virtual void connect(Neuron *neuron, double weight) = 0;
    virtual void sendSignal() = 0;

    double getSignal() const;

protected:
    class Akson
    {
    public:
        void setSignal(double signal);
        double getSignal() const;

    private:
        double m_signal = 0.0;

    };

    Akson m_akson;

};

#endif // ABSTRACTNEURON_HPP
