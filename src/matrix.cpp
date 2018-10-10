#include "matrix.hpp"

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

void Matrix::resize(int rowCount, int columnCount)
{
    m_rows.resize(rowCount);

    for (int i = 0; i < columnCount; i++) {
        m_rows[i].resize(columnCount);
    }
}

Matrix Matrix::resized(int rowCount, int columnCount) const
{
    Matrix resizedMatrix(*this);
    resizedMatrix.resize(rowCount, columnCount);

    return resizedMatrix;
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
