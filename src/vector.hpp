#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <vector>
#include <string>

class Vector
{
public:
    Vector(int n);
    Vector(int n, double val);
    Vector(const std::vector<double> &valueVec);

    int getCount() const;

    double operator[](int index) const;
    double &operator[](int index);

    std::string getString() const;

private:
    std::vector<double> m_values;

};

#endif // VECTOR_HPP
