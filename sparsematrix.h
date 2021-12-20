#ifndef SPARSETRIMATRIX_H
#define SPARSETRIMATRIX_H

#include <vector>

class SparseMatrix
{
public:
    SparseMatrix(int size);

    void setValueAt(int row, int col, double value);
    double getValueAt(int row, int col);

    std::vector<double> operator*(const std::vector<double> &v);

protected:
    std::vector<double> values;
    std::vector<int> colIndex;
    std::vector<int> rowStart;
};

#endif // SPARSETRIMATRIX_H
