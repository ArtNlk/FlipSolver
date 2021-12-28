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
