#include "fluidcell.h"

FluidCell::FluidCell() :
    m_state(AIR),
    m_pressure(0),
    m_velocities()
{
    m_velocities.reserve(6);
    for(int i = 0; i <= 6; i++)
    {
        m_velocities.push_back(std::shared_ptr<double>(new double(0)));
    }
}

FluidCell::CellState FluidCell::getState() const
{
    return m_state;
}

void FluidCell::setState(CellState state)
{
    m_state = state;
}

double FluidCell::getPressure() const
{
    return m_pressure;
}

void FluidCell::setPressure(double pressure)
{
    m_pressure = pressure;
}

double FluidCell::u() const
{
    return *m_velocities[U];
}

void FluidCell::setU(double u)
{
    *m_velocities[U] = u;
}

double FluidCell::v() const
{
    return *m_velocities[V];
}

void FluidCell::setV(double v)
{
    *m_velocities[V] = v;
}

double FluidCell::w() const
{
    return *m_velocities[W];
}

void FluidCell::setW(double w)
{
    *m_velocities[W] = w;
}

double FluidCell::nu() const
{
    return *m_velocities[NU];
}

void FluidCell::setNU(double nu)
{
    *m_velocities[NU] = nu;
}

double FluidCell::nv() const
{
    return *m_velocities[NV];
}

void FluidCell::setNV(double nv)
{
    *m_velocities[NV] = nv;
}

double FluidCell::nw() const
{
    return *m_velocities[NW];
}

void FluidCell::setNW(double nw)
{
    *m_velocities[NW] = nw;
}

std::shared_ptr<double> FluidCell::uPtr() const
{
    return m_velocities[U];
}

void FluidCell::setUPtr(std::shared_ptr<double> uPtr)
{
    m_velocities[U] = uPtr;
}

std::shared_ptr<double> FluidCell::vPtr() const
{
    return m_velocities[V];
}

void FluidCell::setVPtr(std::shared_ptr<double> vPtr)
{
    m_velocities[V] = vPtr;
}

std::shared_ptr<double> FluidCell::wPtr() const
{
    return m_velocities[W];
}

void FluidCell::setWPtr(std::shared_ptr<double> wPtr)
{
    m_velocities[W] = wPtr;
}

std::shared_ptr<double> FluidCell::nuPtr() const
{
    return m_velocities[NU];
}

void FluidCell::setNUPtr(std::shared_ptr<double> nuPtr)
{
    m_velocities[NU] = nuPtr;
}

std::shared_ptr<double> FluidCell::nvPtr() const
{
    return m_velocities[NV];
}

void FluidCell::setNVPtr(std::shared_ptr<double> nvPtr)
{
    m_velocities[NV] = nvPtr;
}

std::shared_ptr<double> FluidCell::nwPtr() const
{
    return m_velocities[NW];
}

void FluidCell::setNWPtr(std::shared_ptr<double> nwPtr)
{
    m_velocities[NW] = nwPtr;
}
