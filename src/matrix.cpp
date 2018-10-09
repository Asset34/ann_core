#include "matrix.hpp"

Matrix::Matrix(int n, int m)
    : m_rowCount(n),
      m_columnCount(m)
{
    m_rows.resize(n);

    for (int i = 0; i < m; i++) {
        m_rows[i] = Vector(m);
    }
}

Matrix::Matrix(int n, int m, double val)
    : m_rowCount(n),
      m_columnCount(m)
{
    m_rows.resize(n);

    for (int i = 0; i < m; i++) {
        m_rows[i] = Vector(val);
    }
}

int Matrix::getRowCount() const
{
    return m_rowCount;
}

int Matrix::getColumnCount() const
{
    return m_columnCount;
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
    Vector resizedRow = row.resized(m_columnCount);

    m_rows[index] = resizedRow;
}

const Vector &Matrix::getRowAt(int index) const
{
    return m_rows[index];
}

void Matrix::setColumnAt(int index, const Vector &column)
{
    Vector resizedColumn = column.resized(m_rowCount);

    for (int i = 0; i < m_rowCount; i++) {
        m_rows[i][index] = resizedColumn[i];
    }
}

Vector Matrix::getColumnAt(int index) const
{
    Vector column(m_rowCount);

    for (int i = 0; i < m_rowCount; i++) {
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
