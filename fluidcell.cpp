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

double FluidCell::getVelocity(CellVelocityIndex index)
{
    return (&m_u)[index];
}

void FluidCell::setVelocity(double velocity, CellVelocityIndex index)
{
    (&m_u)[index] = velocity;
}
