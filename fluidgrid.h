#ifndef FLUIDGRID_H
#define FLUIDGRID_H

#include <vector>
#include <memory>

#include "fluidcell.h"
#include "linearindexable3d.h"

class FluidGrid : public LinearIndexable3d
{
public:
    FluidGrid(int sizeI, int sizeJ, int sizeK, double density, double dt, double gridSideLength);

    inline void getSize(int& out_sizeI, int& out_sizeJ, int& out_sizeK) const
    {
        out_sizeI = m_sizeI-1;
        out_sizeJ = m_sizeJ-1;
        out_sizeK = m_sizeK-1;
    }

    inline void setFluidDensity(double density)
    {
        m_density = density;
    }

    inline double getFluidDensity()
    {
        return m_density;
    }

    inline void setDt(double dt)
    {
        m_dt = dt;
    }

    inline double getDt()
    {
        return m_dt;
    }

    inline void setSideLength(double sideLength)
    {
        m_gridSideLength = sideLength;
    }

    inline double getSideLength()
    {
        return m_gridSideLength;
    }

    inline void setMaterial(int i, int j, int k, FluidCell::CellMaterial material)
    {
        m_cells[linearIndex(i,j,k)].setMaterial(material);
    }

    inline FluidCell::CellMaterial getMaterial(int i, int j, int k)
    {
        return m_cells[linearIndex(i,j,k)].getMaterial();
    }

    inline double getU(int i, int j, int k) const
    {
        return m_cells[linearIndex(i,j,k)].getU();
    }

    inline double getV(int i, int j, int k) const
    {
        return m_cells[linearIndex(i,j,k)].getV();
    }

    inline double getW(int i, int j, int k) const
    {
        return m_cells[linearIndex(i,j,k)].getW();
    }

    inline void setU(int i, int j, int k, double value)
    {
        m_cells[linearIndex(i,j,k)].setU(value);
    }

    inline void setV(int i, int j, int k, double value)
    {
        m_cells[linearIndex(i,j,k)].setV(value);
    }

    inline void setW(int i, int j, int k, double value)
    {
        m_cells[linearIndex(i,j,k)].setW(value);
    }

    inline FluidCell& at(int i, int j, int k)
    {
        return m_cells.at(linearIndex(i,j,k));
    }

private:
    std::vector<FluidCell> m_cells;
    double m_density;
    double m_dt;
    double m_gridSideLength;
};

#endif // FLUIDGRID_H
