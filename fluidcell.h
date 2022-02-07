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

    FluidCell();

    inline CellMaterial getMaterial() const {return m_material;}
    inline void setMaterial(CellMaterial material) {m_material = material;}

    inline void setKnownStatusU(bool status)
    {
        m_knownU = status;
    }

    inline void setKnownU()
    {
        m_knownU = true;
    }

    inline void setUnknownU()
    {
        m_knownU = false;
    }

    inline bool isKnownU() const
    {
        return m_knownU;
    }

    inline void setKnownStatusV(bool status)
    {
        m_knownV = status;
    }

    inline void setKnownV()
    {
        m_knownV = true;
    }

    inline void setUnknownV()
    {
        m_knownV = false;
    }

    inline bool isKnownV() const
    {
        return m_knownV;
    }

    inline void setKnownStatusW(bool status)
    {
        m_knownW = status;
    }

    inline void setKnownW()
    {
        m_knownW = true;
    }

    inline void setUnknownW()
    {
        m_knownW = false;
    }

    inline bool isKnownW() const
    {
        return m_knownW;
    }

    inline double getU() const
    {
        return m_u;
    };

    inline double getV() const
    {
        return m_v;
    };

    inline double getW() const
    {
        return m_w;
    };

    inline double& U()
    {
        return m_u;
    }

    inline double& V()
    {
        return m_v;
    }

    inline double& W()
    {
        return m_w;
    }

    inline void setU(double value)
    {
        m_u = value;
    };

    inline void setV(double value)
    {
        m_v = value;
    };

    inline void setW(double value)
    {
        m_w = value;
    };

protected:
    CellMaterial m_material;
    double m_u;
    double m_v;
    double m_w;
    bool m_knownU;
    bool m_knownV;
    bool m_knownW;
};

#endif // FLUIDCELL_H
