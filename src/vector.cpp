#include "vector.hpp"

Vector::Vector(int n)
    : m_values(n)
{
}

Vector::Vector(int n, double val)
    : m_values(n, val)
{
}

Vector::Vector(const std::vector<double> &valueVec)
    : m_values(valueVec)
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

std::string Vector::getString() const
{
    std::stringstream ss;

    for (int i = 0; i < m_values.size(); i++) {
        ss << m_values[i] << " ";
    }

    return ss.str();
}
