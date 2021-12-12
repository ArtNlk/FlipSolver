#include "fluidgrid.h"

FluidGrid::FluidGrid(int sizeI, int sizeJ, int sizeK):
    m_sizeI(sizeI),
    m_sizeJ(sizeJ),
    m_sizeK(sizeK)
{
    int size = sizeI*sizeJ*sizeK;
    m_cells.reserve(size);
    m_cells.assign(size,FluidCell());
}

void FluidGrid::setMaterial(int i, int j, int k, FluidCell::CellMaterial material)
{
    m_cells[linearIndex(i,j,k)].setMaterial(material);
}

FluidCell::CellMaterial FluidGrid::getMaterial(int i, int j, int k)
{
    return m_cells[linearIndex(i,j,k)].getMaterial();
}

void FluidGrid::setCellVelocity(int i, int j, int k, FluidCell::VelocityIndex index, double velocity)
{
    m_cells[linearIndex(i,j,k)].setVelocity(velocity,index);
}

double FluidGrid::getCellVelocity(int i, int j, int k, FluidCell::VelocityIndex index)
{
    return m_cells[linearIndex(i,j,k)].getVelocity(index);
}

int FluidGrid::linearIndex(int i, int j, int k)
{
    return k*m_sizeI*m_sizeJ + j*m_sizeI+i;
}
