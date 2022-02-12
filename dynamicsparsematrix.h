#ifndef DYNAMICSPARSEMATRIX_H
#define DYNAMICSPARSEMATRIX_H

#include <vector>
#include <utility>

#include "fluidgrid.h"
#include "linearindexable3d.h"

class SparseMatrix;

class DynamicSparseMatrix : public LinearIndexable3d
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
        grid.getSize(m_sizeI, m_sizeJ, m_sizeK);
    }

    inline void setGridSize(const DynamicSparseMatrix &matrix)
    {
        matrix.getGridSize(m_sizeI, m_sizeJ, m_sizeK);
    }

    void setGridSize(const SparseMatrix &matrix);

    inline void getGridSize(int& out_gridSizeI, int& out_gridSizeJ, int& out_gridSizeK) const
    {
        out_gridSizeI = m_sizeI;
        out_gridSizeJ = m_sizeJ;
        out_gridSizeK = m_sizeK;
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
};

#endif // DYNAMICSPARSEMATRIX_H
