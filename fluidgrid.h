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

    inline void setMaterial(int i, int j, int k, FluidCell::CellMaterial material);
    inline FluidCell::CellMaterial getMaterial(int i, int j, int k);

    inline void setCellVelocity(int i, int j, int k, FluidGrid::GridVectorIndex index, double velocity);
    inline double getCellVelocity(int i, int j, int k, FluidGrid::GridVectorIndex index);

    inline void setAdiag(int i, int j, int k, double value);
    inline double getAdiag(int i, int j, int k);

    inline void setCellMatrixEntry(int i, int j, int k, FluidGrid::GridVectorIndex index, double value);
    inline double getCellMatrixEntry(int i, int j, int k, FluidGrid::GridVectorIndex index);

private:
    std::vector<FluidCell> m_cells;
    int m_sizeI;
    int m_sizeJ;
    int m_sizeK;

    inline int linearIndex(int i, int j, int k);
};

#endif // FLUIDGRID_H
