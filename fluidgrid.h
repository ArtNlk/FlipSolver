#ifndef FLUIDGRID_H
#define FLUIDGRID_H

#include <vector>
#include <memory>

#include "fluidcell.h"

class FluidGrid
{
public:
    FluidGrid(int sizeI, int sizeJ, int sizeK);

    inline void setMaterial(int i, int j, int k, FluidCell::CellMaterial material);
    inline FluidCell::CellMaterial getMaterial(int i, int j, int k);

    inline void setCellVelocity(int i, int j, int k, FluidCell::VelocityIndex index, double velocity);
    inline double getCellVelocity(int i, int j, int k, FluidCell::VelocityIndex index);

private:
    std::vector<FluidCell> m_cells;
    int m_sizeI;
    int m_sizeJ;
    int m_sizeK;

    inline int linearIndex(int i, int j, int k);
};

#endif // FLUIDGRID_H
