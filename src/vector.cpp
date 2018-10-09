#include "vector.hpp"

Vector::Vector()
{
}

Vector::Vector(int n)
    : m_values(n)
{
}

Vector::Vector(int n, double val)
    : m_values(n, val)
{
}

int Vector::getCount() const
{
    return m_values.size();
}

double Vector::operator[](int index) const
{
    return m_values[index];
}

double &Vector::operator[](int index)
{
    return m_values[index];
}

void Vector::resize(int n)
{
    m_values.resize(n);
}

Vector Vector::resized(int n) const
{
    Vector resizedVec(*this);
    resizedVec.resize(n);

    return resizedVec;
}
