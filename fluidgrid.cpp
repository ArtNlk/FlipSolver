#include "fluidgrid.h"

FluidGrid::FluidGrid(int sizeI, int sizeJ, int sizeK, double density, double dt, double gridSideLength):
    m_sizeI(sizeI+1),
    m_sizeJ(sizeJ+1),
    m_sizeK(sizeK+1),
    m_density(density),
    m_dt(dt),
    m_gridSideLength(gridSideLength)
{
    int size = (m_sizeI)*(m_sizeJ)*(m_sizeK);
    m_cells.reserve(size);
    m_cells.assign(size,FluidCell());
}
