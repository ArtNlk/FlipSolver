#ifndef FLUIDCELL_H
#define FLUIDCELL_H

#include "vector3d.h"

#include <memory>
#include <vector>

class FluidCell
{
public:

    enum CellState : char {
        AIR   = 0,
        FLUID = 1,
        SOLID = 2
    };

    enum ParamIndex : char {
        U = 0,
        V = 1,
        W = 2,
        NU = 3,
        NV = 4,
        NW = 5
    };

    FluidCell();

    inline CellState getState() const;
    inline void setState(CellState state);

    inline double getPressure() const;
    inline void setPressure(double pressure);

    inline double u() const;
    inline void setU(double u);

    inline double v() const;
    inline void setV(double v);

    inline double w() const;
    inline void setW(double w);

    inline double nu() const;
    inline void setNU(double nu);

    inline double nv() const;
    inline void setNV(double nv);

    inline double nw() const;
    inline void setNW(double nw);

    inline std::shared_ptr<double> uPtr() const;
    inline void setUPtr(std::shared_ptr<double> uPtr);

    inline std::shared_ptr<double> vPtr() const;
    inline void setVPtr(std::shared_ptr<double> vPtr);

    inline std::shared_ptr<double> wPtr() const;
    inline void setWPtr(std::shared_ptr<double> wPtr);

    inline std::shared_ptr<double> nuPtr() const;
    inline void setNUPtr(std::shared_ptr<double> nuPtr);

    inline std::shared_ptr<double> nvPtr() const;
    inline void setNVPtr(std::shared_ptr<double> nvPtr);

    inline std::shared_ptr<double> nwPtr() const;
    inline void setNWPtr(std::shared_ptr<double> nwPtr);

protected:
    CellState m_state;
    double m_pressure;
    std::vector<std::shared_ptr<double>> m_velocities;
};

#endif // FLUIDCELL_H
