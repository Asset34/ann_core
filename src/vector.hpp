#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <vector>

class Vector
{
public:
    Vector();
    Vector(int n);
    Vector(int n, double val);

    int getCount() const;

    double operator[](int index) const;
    double &operator[](int index);

    void resize(int n);
    Vector resized(int n) const;

private:
    std::vector<double> m_values;

};

#endif // VECTOR_HPP