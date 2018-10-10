#include "matrix.hpp"

#include <sstream>

Matrix::Matrix(int rowCount, int columnCount)
    : m_rowCount(rowCount),
      m_columnCount(columnCount),
      m_rows(rowCount, Vector(columnCount))
{
}

Matrix::Matrix(int rowCount, int columnCount, double val)
    : m_rowCount(rowCount),
      m_columnCount(columnCount),
      m_rows(rowCount, Vector(val))
{
}

int Matrix::getRowCount() const
{
    return m_rowCount;
}

int Matrix::getColumnCount() const
{
    return m_columnCount;
}

const Vector &Matrix::operator[](int row) const
{
    return m_rows[row];
}

Vector &Matrix::operator[](int row)
{
    return m_rows[row];
}

void Matrix::setRowAt(int index, const Vector &row)
{
    m_rows[index] = row;
}

const Vector &Matrix::getRowAt(int index) const
{
    return m_rows[index];
}

void Matrix::setColumnAt(int index, const Vector &column)
{
    for (int i = 0; i < m_rowCount; i++) {
        m_rows[i][index] = column[i];
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

std::string Matrix::getString() const
{
    std::stringstream ss;

    for (int i = 0; i < m_rowCount; i++) {
        for (int j = 0; j < m_columnCount; j++) {
            ss << operator[](i).operator[](j) << " ";
        }
        ss << std::endl;
    }

    return ss.str();
}
