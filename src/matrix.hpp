#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <vector>

#include "vector.hpp"

class Matrix
{
public:
    Matrix(int n, int m);
    Matrix(int n, int m, double val);

    int getRowCount() const;
    int getColumnCount() const;

    const Vector &operator[](int column) const;
    Vector &operator[](int column);

    void setRowAt(int index, const Vector &row);
    const Vector &getRowAt(int index) const;

    void setColumnAt(int index, const Vector &column);
    Vector getColumnAt(int index) const;

    void resize(int n, int m);
    Matrix resized(int n, int m) const;

private:
    int m_rowCount;
    int m_columnCount;
    std::vector<Vector> m_rows;

};

#endif // MATRIX_HPP
