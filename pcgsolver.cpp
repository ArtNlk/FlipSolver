#include "pcgsolver.h"

#include <algorithm>

#include "vmath.h"

const double PCGSolver::m_tol = 1.0e-6;

PCGSolver::PCGSolver()
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
