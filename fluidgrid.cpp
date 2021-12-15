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

void FluidGrid::setMaterial(int i, int j, int k, FluidCell::CellMaterial material)
{
    m_cells[linearIndex(i,j,k)].setMaterial(material);
}

FluidCell::CellMaterial FluidGrid::getMaterial(int i, int j, int k)
{
    return m_cells[linearIndex(i,j,k)].getMaterial();
}

void FluidGrid::setCellVelocity(int i, int j, int k, FluidGrid::GridVectorIndex index, double velocity)
{
    switch (index) {
        case FluidGrid::U:
        case FluidGrid::V:
        case FluidGrid::W:
            m_cells[linearIndex(i,j,k)].setVelocity(velocity,static_cast<FluidCell::CellVectorIndex>(index));
            break;

        case FluidGrid::NU:
            m_cells[linearIndex(i-1,j,k)].setVelocity(velocity,static_cast<FluidCell::CellVectorIndex>(index-3));
            break;

        case FluidGrid::NV:
            m_cells[linearIndex(i,j-1,k)].setVelocity(velocity,static_cast<FluidCell::CellVectorIndex>(index-3));
            break;

        case FluidGrid::NW:
            m_cells[linearIndex(i,j,k-1)].setVelocity(velocity,static_cast<FluidCell::CellVectorIndex>(index-3));
            break;
    }
}

double FluidGrid::getCellVelocity(int i, int j, int k, FluidGrid::GridVectorIndex index)
{
    switch (index) {
        case FluidGrid::U:
        case FluidGrid::V:
        case FluidGrid::W:
            return m_cells[linearIndex(i,j,k)].getVelocity(static_cast<FluidCell::CellVectorIndex>(index));
            break;

        case FluidGrid::NU:
            return m_cells[linearIndex(i-1,j,k)].getVelocity(static_cast<FluidCell::CellVectorIndex>(index-3));
            break;

        case FluidGrid::NV:
            return m_cells[linearIndex(i,j-1,k)].getVelocity(static_cast<FluidCell::CellVectorIndex>(index-3));
            break;

        case FluidGrid::NW:
            return m_cells[linearIndex(i,j,k-1)].getVelocity(static_cast<FluidCell::CellVectorIndex>(index-3));
            break;
    }
}

void FluidGrid::setAdiag(int i, int j, int k, double value)
{
    m_cells[linearIndex(i,j,k)].setAdiag(value);
}

double FluidGrid::getAdiag(int i, int j, int k)
{
    return m_cells[linearIndex(i,j,k)].getAdiag();
}

void FluidGrid::setCellMatrixEntry(int i, int j, int k, FluidGrid::GridVectorIndex index, double value)
{
    switch (index) {
        case FluidGrid::U:
        case FluidGrid::V:
        case FluidGrid::W:
            m_cells[linearIndex(i,j,k)].setMatrixValue(value,static_cast<FluidCell::CellVectorIndex>(index));
            break;

        case FluidGrid::NU:
            m_cells[linearIndex(i-1,j,k)].setMatrixValue(value,static_cast<FluidCell::CellVectorIndex>(index-3));
            break;

        case FluidGrid::NV:
            m_cells[linearIndex(i,j-1,k)].setMatrixValue(value,static_cast<FluidCell::CellVectorIndex>(index-3));
            break;

        case FluidGrid::NW:
            m_cells[linearIndex(i,j,k-1)].setMatrixValue(value,static_cast<FluidCell::CellVectorIndex>(index-3));
            break;
    }
}

double FluidGrid::getCellMatrixEntry(int i, int j, int k, GridVectorIndex index)
{
    switch (index) {
        case FluidGrid::U:
        case FluidGrid::V:
        case FluidGrid::W:
            return m_cells[linearIndex(i,j,k)].getMatrixValue(static_cast<FluidCell::CellVectorIndex>(index));
            break;

        case FluidGrid::NU:
            return m_cells[linearIndex(i-1,j,k)].getMatrixValue(static_cast<FluidCell::CellVectorIndex>(index-3));
            break;

        case FluidGrid::NV:
            return m_cells[linearIndex(i,j-1,k)].getMatrixValue(static_cast<FluidCell::CellVectorIndex>(index-3));
            break;

        case FluidGrid::NW:
            return m_cells[linearIndex(i,j,k-1)].getMatrixValue(static_cast<FluidCell::CellVectorIndex>(index-3));
            break;
    }
}

int FluidGrid::linearIndex(int i, int j, int k)
{
    return k*m_sizeI*m_sizeJ + j*m_sizeI+i;
}
