#include "fluidgrid.h"

FluidGrid::FluidGrid(int sizeI, int sizeJ, int sizeK):
    m_sizeI(sizeI+1),
    m_sizeJ(sizeJ+1),
    m_sizeK(sizeK+1)
{
    int size = (m_sizeI)*(m_sizeJ)*(m_sizeK);
    m_cells.reserve(size);
    m_cells.assign(size,FluidCell());
}
