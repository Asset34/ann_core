#ifndef ENTITIES_HPP
#define ENTITIES_HPP

#include <functional>
#include <vector>

using ActivationFunc = std::function<double (double)>;
using WeightVec = std::vector<double>;
using WeightMat = std::vector<std::vector<double>>;

#endif // ENTITIES_HPP
