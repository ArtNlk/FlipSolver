#ifndef SPARSETRIMATRIX_H
#define SPARSETRIMATRIX_H

#include <vector>
#include <utility>

#include "dynamicsparsematrix.h"

class SparseMatrix
{
public:
    typedef std::pair<int,double> StaticRowUnit;

    SparseMatrix(const DynamicSparseMatrix &dynamicMatrix);

    double getValue(int row, int col);

    std::vector<double> operator*(const std::vector<double> &v);

protected:
    std::vector<StaticRowUnit> m_values;
    std::vector<int> m_rowStart;
    int m_size;
};

#endif // SPARSETRIMATRIX_H
