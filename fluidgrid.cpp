#include "fluidgrid.h"

FluidGrid::FluidGrid(int sizeI, int sizeJ, int sizeK):
    m_sizeI(sizeI),
    m_sizeJ(sizeJ),
    m_sizeK(sizeK)
{
    int size = (sizeI+1)*(sizeJ+1)*(sizeK+1);
    m_cells.reserve(size);
    m_cells.assign(size,FluidCell());
}
