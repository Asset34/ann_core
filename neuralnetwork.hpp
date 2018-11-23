#ifndef NEURALNETWORK_HPP
#define NEURALNETWORK_HPP

#include <vector>
#include <tuple>

struct LearnUnit
{
    std::vector<double> sample;
    std::vector<double> result;
};

class NeuralNetwork
{
public:
    NeuralNetwork(size_t inputSize, size_t memorySize);
    virtual ~NeuralNetwork() = default;

    virtual bool learn(const std::vector<LearnUnit> &samples) = 0;
    virtual std::tuple<std::vector<double>, bool> recognize(const std::vector<double> &sample) = 0;

    virtual void rebuild(size_t inputSize, size_t memorySize) = 0;

protected:
    size_t m_inputSize;
    size_t m_memorySize;

};

#endif // NEURALNETWORK_HPP
