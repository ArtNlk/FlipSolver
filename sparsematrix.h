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

    double getValue(int row, int col) const;

    inline int rowCount() const
    {
        return m_rowStart.size()-1;
    };

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

    inline int linearIndex(int i, int j, int k) const
    {
        return i*m_gridSizeJ*m_gridSizeK + j*m_gridSizeK+k;
    }

    inline double Adiag(int i, int j, int k) const
    {
        int index = linearIndex(i,j,k);
        return getValue(index,index);
    }

    inline double Ax(int i, int j, int k) const
    {
        int rowIndex = linearIndex(i,j,k);
        int colIndex = linearIndex(i+1,j,k);

        return getValue(rowIndex,colIndex);
    }

    inline double Ay(int i, int j, int k) const
    {
        int rowIndex = linearIndex(i,j,k);
        int colIndex = linearIndex(i,j+1,k);

        return getValue(rowIndex,colIndex);
    }

    inline double Az(int i, int j, int k) const
    {
        int rowIndex = linearIndex(i,j,k);
        int colIndex = linearIndex(i,j,k+1);

        return getValue(rowIndex,colIndex);
    }

    std::vector<double> operator*(const std::vector<double> &v) const;

protected:
    std::vector<StaticRowUnit> m_values;
    std::vector<int> m_rowStart;
    int m_size;

    int m_gridSizeI;
    int m_gridSizeJ;
    int m_gridSizeK;
};

#endif // SPARSETRIMATRIX_H
