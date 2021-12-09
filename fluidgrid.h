#ifndef FLUIDGRID_H
#define FLUIDGRID_H

#include <vector>
#include <memory>

#include "fluidcell.h"

class FluidGrid
{
public:
    FluidGrid();

private:
    std::vector<std::shared_ptr<FluidCell>> m_cells;
};

#endif // FLUIDGRID_H
