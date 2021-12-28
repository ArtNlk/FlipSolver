#ifndef FLUIDGRID_H
#define FLUIDGRID_H

#include <vector>
#include <memory>

#include "fluidcell.h"

class FluidGrid
{
public:

    enum GridVectorIndex : char {
        U = 0,
        V = 1,
        W = 2,
        NU = 3,
        NV = 4,
        NW = 5
    };

    FluidGrid(int sizeI, int sizeJ, int sizeK);

    inline void setMaterial(int i, int j, int k, FluidCell::CellMaterial material)
    {
        m_cells[linearIndex(i,j,k)].setMaterial(material);
    }

    inline FluidCell::CellMaterial getMaterial(int i, int j, int k)
    {
        return m_cells[linearIndex(i,j,k)].getMaterial();
    }

    inline void setCellVelocity(int i, int j, int k, FluidGrid::GridVectorIndex index, double velocity)
    {
        switch (index) {
            case FluidGrid::U:
            case FluidGrid::V:
            case FluidGrid::W:
                m_cells[linearIndex(i+1,j+1,k+1)].setVelocity(velocity,static_cast<FluidCell::CellVectorIndex>(index));
                break;

            case FluidGrid::NU:
                m_cells[linearIndex(i,j+1,k+1)].setVelocity(velocity,static_cast<FluidCell::CellVectorIndex>(index-3));
                break;

            case FluidGrid::NV:
                m_cells[linearIndex(i+1,j,k+1)].setVelocity(velocity,static_cast<FluidCell::CellVectorIndex>(index-3));
                break;

            case FluidGrid::NW:
                m_cells[linearIndex(i+1,j+1,k)].setVelocity(velocity,static_cast<FluidCell::CellVectorIndex>(index-3));
                break;
        }
    }

    inline double getCellVelocity(int i, int j, int k, FluidGrid::GridVectorIndex index)
    {
        switch (index) {
            case FluidGrid::U:
            case FluidGrid::V:
            case FluidGrid::W:
                return m_cells[linearIndex(i+1,j+1,k+1)].getVelocity(static_cast<FluidCell::CellVectorIndex>(index));
                break;

            case FluidGrid::NU:
                return m_cells[linearIndex(i,j+1,k+1)].getVelocity(static_cast<FluidCell::CellVectorIndex>(index-3));
                break;

            case FluidGrid::NV:
                return m_cells[linearIndex(i+1,j,k+1)].getVelocity(static_cast<FluidCell::CellVectorIndex>(index-3));
                break;

            case FluidGrid::NW:
                return m_cells[linearIndex(i+1,j+1,k)].getVelocity(static_cast<FluidCell::CellVectorIndex>(index-3));
                break;
        }
    }

private:
    std::vector<FluidCell> m_cells;
    int m_sizeI;
    int m_sizeJ;
    int m_sizeK;

    inline int linearIndex(int i, int j, int k)
    {
        return k*m_sizeI*m_sizeJ + j*m_sizeI+i;
    }
};

#endif // FLUIDGRID_H
