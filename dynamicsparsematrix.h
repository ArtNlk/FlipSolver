#ifndef DYNAMICSPARSEMATRIX_H
#define DYNAMICSPARSEMATRIX_H

#include <vector>
#include <utility>

#include "fluidgrid.h"

class SparseMatrix;

class DynamicSparseMatrix
{
public:
    typedef std::pair<int,double> SparseRowUnit;
    typedef std::vector<SparseRowUnit> SparseRow;

    DynamicSparseMatrix(int size, int avgRowLength = 7);

    DynamicSparseMatrix(FluidGrid &grid);

    void resize(int newSize);
    int size() const;

    inline void setGridSize(const FluidGrid &grid)
    {
        grid.getSize(m_gridSizeI, m_gridSizeJ, m_gridSizeK);
    }

    inline void setGridSize(const DynamicSparseMatrix &matrix)
    {
        matrix.getGridSize(m_gridSizeI, m_gridSizeJ, m_gridSizeK);
    }

    void setGridSize(const SparseMatrix &matrix);

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

    inline int linearIndex(int i, int j, int k)
    {
        return i*m_gridSizeJ*m_gridSizeK + j*m_gridSizeK+k;
    }

    inline void setAdiag(int i, int j, int k, double value)
    {
        int index = linearIndex(i,j,k);
        setValue(index, index, value);
    }

    inline void setAx(int i, int j, int k, double value)
    {
        int rowIndex = linearIndex(i,j,k);
        int colIndex = linearIndex(i+1,j,k);

        return setValue(rowIndex,colIndex, value);
    }

    inline void setAy(int i, int j, int k, double value)
    {
        int rowIndex = linearIndex(i,j,k);
        int colIndex = linearIndex(i,j+1,k);

        return setValue(rowIndex,colIndex, value);
    }

    inline void setAz(int i, int j, int k, double value)
    {
        int rowIndex = linearIndex(i,j,k);
        int colIndex = linearIndex(i,j,k+1);

        return setValue(rowIndex,colIndex, value);
    }

    inline void modifyAdiag(int i, int j, int k, double value)
    {
        int index = linearIndex(i,j,k);
        setValue(index, index, getValue(index,index) + value);
    }

    inline void modifyAx(int i, int j, int k, double value)
    {
        int rowIndex = linearIndex(i,j,k);
        int colIndex = linearIndex(i+1,j,k);

        return setValue(rowIndex,colIndex, getValue(rowIndex, colIndex) + value);
    }

    inline void modifyAy(int i, int j, int k, double value)
    {
        int rowIndex = linearIndex(i,j,k);
        int colIndex = linearIndex(i,j+1,k);

        return setValue(rowIndex,colIndex, getValue(rowIndex, colIndex) + value);
    }

    inline void modifyAz(int i, int j, int k, double value)
    {
        int rowIndex = linearIndex(i,j,k);
        int colIndex = linearIndex(i,j,k+1);

        return setValue(rowIndex,colIndex, getValue(rowIndex, colIndex) + value);
    }

    inline int rowSize(int rowIndex) const { return m_rows[rowIndex].size();}

    inline int elementCount() const { return m_elementCount;}

    inline const std::vector<SparseRow> *data() const { return &m_rows;}

    void setValue(int rowIndex, int columnIndex, double value);
    double getValue(int rowIndex, int columnIndex) const;
    bool getValue(int rowIndex, int columnIndex, double &out) const;

protected:
    std::vector<SparseRow> m_rows;
    int m_size;
    int m_elementCount;

    int m_gridSizeI;
    int m_gridSizeJ;
    int m_gridSizeK;
};

#endif // DYNAMICSPARSEMATRIX_H
