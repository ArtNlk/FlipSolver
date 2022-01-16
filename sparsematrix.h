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

    inline int rowCount() const
    {
        return m_rowStart.size()-1;
    };

    inline void getGridSize(int& out_gridSizeI, int& out_gridSizeJ, int& out_gridSizeK)
    {
        out_gridSizeI = m_gridSizeI;
        out_gridSizeJ = m_gridSizeJ;
        out_gridSizeK = m_gridSizeK;
    }

    inline int gridSizeI()
    {
        return m_gridSizeI;
    }

    inline int gridSizeJ()
    {
        return m_gridSizeJ;
    }

    inline int gridSizeK()
    {
        return m_gridSizeK;
    }

    inline int linearIndex(int i, int j, int k)
    {
        return k*m_gridSizeI*m_gridSizeJ + j*m_gridSizeI+i;
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
