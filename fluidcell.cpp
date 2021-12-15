#include "fluidcell.h"

#include <stdexcept>

FluidCell::FluidCell() :
    m_material(AIR),
    m_pressure(0),
    m_u(0),
    m_v(0),
    m_w(0)
{
}

FluidCell::CellMaterial FluidCell::getMaterial() const
{
    return m_material;
}

void FluidCell::setMaterial(CellMaterial material)
{
    m_material = material;
}

double FluidCell::getPressure() const
{
    return m_pressure;
}

void FluidCell::setPressure(double pressure)
{
    m_pressure = pressure;
}

double FluidCell::getVelocity(CellVectorIndex index)
{
    return (&m_u)[index];
}

void FluidCell::setVelocity(double velocity, CellVectorIndex index)
{
    (&m_u)[index] = velocity;
}

double FluidCell::getAdiag()
{
    return m_Adiag;
}

void FluidCell::setAdiag(double Adiag)
{
    m_Adiag = Adiag;
}

double FluidCell::getMatrixValue(CellVectorIndex index)
{
    return (&m_Ax)[index];
}

void FluidCell::setMatrixValue(double value, CellVectorIndex index)
{
    (&m_Ax)[index] = value;
}
