#ifndef PCGSOLVER_H
#define PCGSOLVER_H

#include "sparsematrix.h"
#include "fluidgrid.h"

class PCGSolver
{
public:
    PCGSolver();

    bool solve(const FluidGrid& grid, const SparseMatrix &matrix, std::vector<double> &result, const std::vector<double> &vec, int iterLimit = 200);

protected:
    void applyICPrecond(std::vector<double> &vector);
    double calcPrecond(const FluidGrid &grid, const SparseMatrix &matrix, double value);

    std::vector<double> m_residual;
    std::vector<double> m_aux;
    std::vector<double> m_search;
    static const double m_tol;
};

#endif // PCGSOLVER_H
