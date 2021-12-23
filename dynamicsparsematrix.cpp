#include "dynamicsparsematrix.h"

DynamicSparseMatrix::DynamicSparseMatrix(int size, int avgRowLength) :
    m_size(size),
    m_rows(size)
{
    for(int i = 0; i < size; i++)
    {
        m_rows[i].reserve(avgRowLength);
    }
}

void DynamicSparseMatrix::resize(int newSize)
{
    m_size = newSize;
    m_rows.resize(newSize);
}

int DynamicSparseMatrix::size() const
{
    return m_size;
}

void DynamicSparseMatrix::setValue(int rowIndex, int columnIndex, double value)
{
    SparseRow &targetRow = m_rows[rowIndex];
    for(int column = 0; column < m_size; column++)
    {
        if(targetRow[column].first == columnIndex)
        {
            targetRow[column].second = value;
            return;
        }
        else if(targetRow[column].first > columnIndex)
        {
            targetRow.insert(targetRow.begin()+column,SparseRowUnit(column,value));
            return;
        }
    }
    targetRow.push_back(SparseRowUnit(columnIndex,value));
}

double DynamicSparseMatrix::getValue(int rowIndex, int columnIndex) const
{
    const SparseRow &targetRow = m_rows[rowIndex];
    for(int column = 0; column < m_size; column++)
    {
        if(targetRow[column].first == columnIndex)
        {
            return targetRow[column].second;
        }
    }

    return 0;
}
