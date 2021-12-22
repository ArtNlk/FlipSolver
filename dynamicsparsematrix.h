#ifndef DYNAMICSPARSEMATRIX_H
#define DYNAMICSPARSEMATRIX_H

#include <vector>
#include <utility>

class DynamicSparseMatrix
{
public:
    DynamicSparseMatrix();

    void setValue(int rowIndex, int columnIndex, double value);
    double getValue(int rowIndex, int columnIndex);

protected:
    std::vector<std::vector<std::pair<int,double>>> m_rows;
};

#endif // DYNAMICSPARSEMATRIX_H
