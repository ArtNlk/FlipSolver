#ifndef FLUIDCELL_H
#define FLUIDCELL_H

#include "vector3d.h"

#include <memory>
#include <vector>

#include <iostream>

class FluidCell
{
public:

    enum CellMaterial : char {
        AIR   = 0,
        FLUID = 1,
        SOLID = 2
    };

    enum CellVectorIndex : char {
        U = 0,
        V = 1,
        W = 2,
    };

    FluidCell();

    inline CellMaterial getMaterial() const {return m_material;}
    inline void setMaterial(CellMaterial material) {m_material = material;}

    inline double getPressure() const {return m_pressure;}
    inline void setPressure(double pressure) {m_pressure = pressure;}

    inline double getVelocity(CellVectorIndex index) {return (&this->m_u)[index];}
    inline void setVelocity(double velocity, CellVectorIndex index) {(&this->m_u)[index] = velocity;}

protected:
    CellMaterial m_material;
    double m_pressure;
    double m_u;
    double m_v;
    double m_w;
};

#endif // FLUIDCELL_H
