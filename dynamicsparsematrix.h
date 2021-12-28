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

    inline int rowSize(int rowIndex) const { return m_rows[rowIndex].size();}

    inline int elementCount() const { return m_elementCount;}

    inline const std::vector<SparseRow> *data() const { return &m_rows;}

    void setValue(int rowIndex, int columnIndex, double value);
    double getValue(int rowIndex, int columnIndex) const;

protected:
    std::vector<SparseRow> m_rows;
    int m_size;
    int m_elementCount;
};

#endif // DYNAMICSPARSEMATRIX_H
