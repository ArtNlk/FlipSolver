#include "fluidcell.h"

#include <stdexcept>

FluidCell::FluidCell() :
    m_material(AIR),
    m_u(0),
    m_v(0),
    m_w(0),
    m_knownU(false),
    m_knownV(false),
    m_knownW(false)
{
}
