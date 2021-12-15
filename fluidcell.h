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

    enum CellVectorIndex : char {
        U = 0,
        V = 1,
        W = 2,
    };

    FluidCell();

    inline CellMaterial getMaterial() const;
    inline void setMaterial(CellMaterial material);

    inline double getPressure() const;
    inline void setPressure(double pressure);

    inline double getVelocity(CellVectorIndex index);
    inline void setVelocity(double velocity, CellVectorIndex index);

    inline double getAdiag();
    inline void setAdiag(double Adiag);

    inline double getMatrixValue(CellVectorIndex index);
    inline void setMatrixValue(double value, CellVectorIndex index);

protected:
    CellMaterial m_material;
    double m_pressure;
    double m_u;
    double m_v;
    double m_w;
    double m_Adiag;
    double m_Ax;
    double m_Ay;
    double m_Az;
};

#endif // FLUIDCELL_H
