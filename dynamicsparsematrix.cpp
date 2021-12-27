#include "dynamicsparsematrix.h"

DynamicSparseMatrix::DynamicSparseMatrix(int size, int avgRowLength) :
    m_size(size),
    m_rows(size),
    m_elementCount(0)
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

int DynamicSparseMatrix::rowSize(int rowIndex) const
{
    return m_rows[rowIndex].size();
}

int DynamicSparseMatrix::elementCount() const
{
    return m_elementCount;
}

const std::vector<DynamicSparseMatrix::SparseRow> *DynamicSparseMatrix::data() const
{
    return &m_rows;
}

void DynamicSparseMatrix::setValue(int rowIndex, int columnIndex, double value)
{
    SparseRow &targetRow = m_rows[rowIndex];
    for(int column = 0; column < targetRow.size(); column++)
    {
        if(targetRow[column].first == columnIndex)
        {
            targetRow[column].second = value;
            return;
        }
        else if(targetRow[column].first > columnIndex)
        {
            targetRow.insert(targetRow.begin()+column,SparseRowUnit(column,value));
            m_elementCount++;
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
