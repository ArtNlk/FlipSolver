#include "pcgsolver.h"

#include <algorithm>

#include "vmath.h"
#include "cmath"

const double PCGSolver::m_tol = 1.0e-6;

PCGSolver::PCGSolver() :
    m_precondCache(1,1)
{

}

bool PCGSolver::solve(const SparseMatrix &matrix, std::vector<double> &result, const std::vector<double> &vec, int iterLimit)
{
    result.assign(matrix.rowCount(),0);
    if(isZero(vec))
    {
        return false;
    }
    m_residual = vec;
    m_aux = m_residual;
    applyICPrecond(m_aux);
    m_search = m_aux;
    double sigma = dot(m_aux,m_residual);

    for(int i = 0; i < iterLimit; i++)
    {
        m_aux = matrix * m_search;
        double alpha = sigma/dot(m_aux,m_search);
        addMul(result,result,m_search,alpha);
        subMul(m_residual,m_residual,m_aux,alpha);
        if(maxAbs(m_residual) <= m_tol)
        {
            return false;
        }
        m_aux = m_residual;
        applyICPrecond(m_aux);
        double newSigma = dot(m_aux,m_residual);
        double beta = newSigma/sigma;
        addMul(m_search,m_aux,m_search,beta);
        sigma = newSigma;
    }

    return true;
}

double PCGSolver::calcPrecond(const SparseMatrix &matrix)
{
    m_precondCache = DynamicSparseMatrix(1);
    m_precondCache.setGridSize(matrix);
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
