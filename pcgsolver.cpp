#include "pcgsolver.h"

#include <algorithm>

#include "vmath.h"
#include "cmath"

const double PCGSolver::m_tol = 1.0e-6;

PCGSolver::PCGSolver() :
    m_precondCache(1,1)
{

}

bool PCGSolver::solve(const SparseMatrix &matrix, FluidGrid &grid, std::vector<double> &result, const std::vector<double> &vec, int iterLimit)
{
    result.assign(matrix.rowCount(),0);
    if (isZero(vec))
    {
        return false;
    }
    calcPrecond(matrix,grid);
    m_residual = vec;
    m_aux = m_residual;
    applyICPrecond(matrix,m_aux,grid);
    m_search = m_aux;
    double sigma = dot(m_aux,m_residual);

    for (int i = 0; i < iterLimit; i++)
    {
        m_aux = matrix * m_search;
        double alpha = sigma/dot(m_aux,m_search);
        addMul(result,result,m_search,alpha);
        subMul(m_residual,m_residual,m_aux,alpha);
        if (maxAbs(m_residual) <= m_tol)
        {
            return true;
        }
        m_aux = m_residual;
        applyICPrecond(matrix,m_aux,grid);
        double newSigma = dot(m_aux,m_residual);
        double beta = newSigma/sigma;
        addMul(m_search,m_aux,m_search,beta);
        sigma = newSigma;
    }

    return false;
}

void PCGSolver::applyICPrecond(const SparseMatrix &matrix, std::vector<double> &vector, FluidGrid &grid)
{
    double t = 0;
    std::vector<double> temp(vector.size(),0);
    for (int i = 1; i < grid.sizeI(); i++)
    {
        for (int j = 1; j < grid.sizeJ(); j++)
        {
            for (int k = 1; k < grid.sizeK(); k++)
            {
                if (grid.getMaterial(i,j,k) == FluidCell::FLUID)
                {
                    t = vector[matrix.linearIndex(i-1,j,k)] - (matrix.Ax(i-1,j,k) * precond(matrix,i-1,j,k) * temp[matrix.linearIndex(i-1,j,k)])
                                                            - (matrix.Ax(i,j-1,k) * precond(matrix,i,j-1,k) * temp[matrix.linearIndex(i,j-1,k)])
                                                            - (matrix.Ax(i,j,k-1) * precond(matrix,i,j,k-1) * temp[matrix.linearIndex(i,j,k-1)]);
                    temp[matrix.linearIndex(i,j,k)] = t*precond(matrix,i,j,k);
                }
            }
        }
    }

    for (int i = grid.sizeI(); i >= 1; i--)
    {
        for (int j = grid.sizeJ(); j >= 1; j--)
        {
            for (int k = grid.sizeK(); k >= 1; k--)
            {
                if (grid.getMaterial(i,j,k) == FluidCell::FLUID)
                {
                    t = temp[matrix.linearIndex(i,j,k)] - (matrix.Ax(i,j,k) * precond(matrix,i,j,k) * temp[matrix.linearIndex(i+1,j,k)])
                                                        - (matrix.Ax(i,j,k) * precond(matrix,i,j,k) * temp[matrix.linearIndex(i,j+1,k)])
                                                        - (matrix.Ax(i,j,k) * precond(matrix,i,j,k) * temp[matrix.linearIndex(i,j,k+1)]);
                    vector[matrix.linearIndex(i,j,k)] = t*precond(matrix,i,j,k);
                }
            }
        }
    }
}

void PCGSolver::calcPrecond(const SparseMatrix &matrix, FluidGrid &grid)
{
    m_precondCache = DynamicSparseMatrix(1);
    m_precondCache.setGridSize(matrix);
    for (int i = 1; i < grid.sizeI(); i++)
    {
        for (int j = 1; j < grid.sizeJ(); j++)
        {
            for (int k = 1; k < grid.sizeK(); k++)
            {
                if (grid.getMaterial(i,j,k) == FluidCell::FLUID)
                {
                    precond(matrix,i,j,k);
                }
            }
        }
    }
}

double PCGSolver::precond(const SparseMatrix &m, int i, int j, int k)
{
    double temp;
    if (m_precondCache.getValue(0,m_precondCache.linearIndex(i,j,k),temp))
    {
        return temp;
    }

    const double tuning = 0.97;
    const double safety = 0.25;

    temp = m.Adiag(i,j,k)
            - (m.Ax(i-1,j,k)*precond(m,i-1,j,k))*(m.Ax(i-1,j,k)*precond(m,i-1,j,k))
            - (m.Ay(i,j-1,k)*precond(m,i,j-1,k))*(m.Ay(i,j-1,k)*precond(m,i,j-1,k))
            - (m.Az(i,j,k-1)*precond(m,i,j,k-1))*(m.Az(i,j,k-1)*precond(m,i,j,k-1))

            - tuning*(m.Ax(i-1,j,k)*(m.Ay(i-1,j,k) + m.Az(i-1,j,k))*precond(m,i-1,j,k)*precond(m,i-1,j,k)
                      + m.Ay(i,j-1,k)*(m.Ax(i,j-1,k) + m.Az(i,j-1,k))*precond(m,i,j-1,k)*precond(m,i,j-1,k)
                      + m.Az(i,j,k-1)*(m.Ax(i,j,k-1) + m.Ay(i,j,k-1))*precond(m,i,j,k-1)*precond(m,i,j,k-1));

    if(temp < safety*m.Adiag(i,j,k))
    {
        temp = m.Adiag(i,j,k);
    }

    temp = 1/std::sqrt(temp);

    m_precondCache.setValue(0,m_precondCache.linearIndex(i,j,k),temp);

    return temp;
}
