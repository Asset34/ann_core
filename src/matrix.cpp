#include "matrix.hpp"

Matrix::Matrix(int n, int m)
{
    m_rows.resize(n);

    for (int i = 0; i < m; i++) {
        m_rows[i] = Vector(m);
    }
}

Matrix::Matrix(int n, int m, double val)
{
    m_rows.resize(n);

    for (int i = 0; i < m; i++) {
        m_rows[i] = Vector(val);
    }
}

int Matrix::getRowCount() const
{
    return m_rows.size();
}

int Matrix::getColumnCount() const
{
    return m_rows[0].getCount();
}

const Vector &Matrix::operator[](int column) const
{
    return m_rows[column];
}

Vector &Matrix::operator[](int column)
{
    return m_rows[column];
}

void Matrix::setRowAt(int index, const Vector &row)
{
    m_rows[index] = row;
}

const Vector &Matrix::getRowAt(int index)
{
    return m_rows[index];
}

void Matrix::setColumnAt(int index, const Vector &column)
{
    Vector normColumn(column);
    normColumn.resize(m_rows.size());

    for (int i = 0; i < m_rows.size(); i++) {
        m_rows[i][index] = normColumn[i];
    }
}

Vector Matrix::getColumnAt(int index)
{
    Vector column(m_rows.size());

    for (int i = 0; i < m_rows.size(); i++) {
        column[i] = m_rows[i][index];
    }

    return column;
}

void Matrix::resize(int n, int m)
{
    m_rows.resize(n);

    for (int i = 0; i < m; i++) {
        m_rows[i].resize(m);
    }
}

Matrix Matrix::resized(int n, int m) const
{
    Matrix resizedMatrix(*this);
    resizedMatrix.resize(n, m);

    return resizedMatrix;
}
