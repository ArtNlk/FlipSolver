#ifndef SPARSETRIMATRIX_H
#define SPARSETRIMATRIX_H

#include <vector>

class SparseMatrix
{
public:
    SparseMatrix(int size);

    double getValueAt(int row, int col);

    std::vector<double> operator*(const std::vector<double> &v);

protected:
    std::vector<double> m_values;
    std::vector<int> m_colIndex;
    std::vector<int> m_rowStart;
    int m_size;
};

#endif // SPARSETRIMATRIX_H
