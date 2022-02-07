#ifndef FLIPSOLVER_H
#define FLIPSOLVER_H

#include "pcgsolver.h"
#include "fluidgrid.h"

class FlipSolver
{
public:
    FlipSolver(int sizeX, int sizeY, int sizeZ, double fluidDensity, double timestepSize, double sideLength);

protected:
    void project();

    void calcRhs(std::vector<double> &rhs);

    FluidGrid m_grid;
    PCGSolver m_pcgSolver;
};

#endif // FLIPSOLVER_H
