#include "fluidgrid.h"

FluidGrid::FluidGrid(int sizeI, int sizeJ, int sizeK, double density, double dt, double gridSideLength):
    LinearIndexable3d(sizeI,sizeJ,sizeK),
    m_density(density),
    m_dt(dt),
    m_gridSideLength(gridSideLength)
{
    int size = (m_sizeI)*(m_sizeJ)*(m_sizeK);
    m_cells.reserve(size);
    m_cells.assign(size,FluidCell());
}
