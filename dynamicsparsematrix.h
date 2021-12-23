#ifndef DYNAMICSPARSEMATRIX_H
#define DYNAMICSPARSEMATRIX_H

#include <vector>
#include <utility>

class DynamicSparseMatrix
{
public:
    typedef std::pair<int,double> SparseRowUnit;
    typedef std::vector<SparseRowUnit> SparseRow;

    DynamicSparseMatrix(int size, int avgRowLength = 7);


    void resize(int newSize);
    int size() const;

    void setValue(int rowIndex, int columnIndex, double value);
    double getValue(int rowIndex, int columnIndex) const;

protected:
    std::vector<SparseRow> m_rows;
    int m_size;
};

#endif // DYNAMICSPARSEMATRIX_H
