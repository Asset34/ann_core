#ifndef ENTITIES_HPP
#define ENTITIES_HPP

#include <functional>
#include <vector>

typedef std::function<double (double)> ActivationFunc;
typedef std::vector<double> WeightVec;
typedef std::vector<std::vector<double>> WeightMat;

#endif // ENTITIES_HPP
