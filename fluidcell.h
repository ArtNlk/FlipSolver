#ifndef FLUIDCELL_H
#define FLUIDCELL_H

#include "vector3d.h"

#include <memory>
#include <vector>

class FluidCell
{
public:

    enum CellMaterial : char {
        AIR   = 0,
        FLUID = 1,
        SOLID = 2
    };

    enum CellVelocityIndex : char {
        U = 0,
        V = 1,
        W = 2,
    };

    FluidCell();

    inline CellMaterial getMaterial() const;
    inline void setMaterial(CellMaterial material);

    inline double getPressure() const;
    inline void setPressure(double pressure);

    inline double getVelocity(CellVelocityIndex index);
    inline void setVelocity(double velocity, CellVelocityIndex index);

protected:
    CellMaterial m_material;
    double m_pressure;
    double m_u;
    double m_v;
    double m_w;
};

#endif // FLUIDCELL_H
