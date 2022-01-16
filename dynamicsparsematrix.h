#ifndef DYNAMICSPARSEMATRIX_H
#define DYNAMICSPARSEMATRIX_H

#include <vector>
#include <utility>

#include "fluidgrid.h"

class DynamicSparseMatrix
{
public:
    typedef std::pair<int,double> SparseRowUnit;
    typedef std::vector<SparseRowUnit> SparseRow;

    DynamicSparseMatrix(int size, int avgRowLength = 7);

    void resize(int newSize);
    int size() const;

    inline void setGridSize(FluidGrid &grid)
    {
        grid.getSize(m_gridSizeI, m_gridSizeJ, m_gridSizeK);
    }

    inline void getGridSize(int& out_gridSizeI, int& out_gridSizeJ, int& out_gridSizeK) const
    {
        out_gridSizeI = m_gridSizeI;
        out_gridSizeJ = m_gridSizeJ;
        out_gridSizeK = m_gridSizeK;
    }

    inline int gridSizeI() const
    {
        return m_gridSizeI;
    }

    inline int gridSizeJ() const
    {
        return m_gridSizeJ;
    }

    inline int gridSizeK() const
    {
        return m_gridSizeK;
    }

    inline int rowSize(int rowIndex) const { return m_rows[rowIndex].size();}

    inline int elementCount() const { return m_elementCount;}

    inline const std::vector<SparseRow> *data() const { return &m_rows;}

    void setValue(int rowIndex, int columnIndex, double value);
    double getValue(int rowIndex, int columnIndex) const;

protected:
    std::vector<SparseRow> m_rows;
    int m_size;
    int m_elementCount;

    int m_gridSizeI;
    int m_gridSizeJ;
    int m_gridSizeK;
};

#endif // DYNAMICSPARSEMATRIX_H
