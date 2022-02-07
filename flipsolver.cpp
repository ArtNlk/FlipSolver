#include "flipsolver.h"

FlipSolver::FlipSolver(int sizeX, int sizeY, int sizeZ, double fluidDensity, double timestepSize,  double sideLength) :
    m_grid(sizeX, sizeY, sizeZ, fluidDensity, timestepSize, sideLength)
{

}

void FlipSolver::project()
{
    std::vector<double> rhs(0,m_grid.sizeI() * m_grid.sizeJ() * m_grid.sizeK());
    calcRhs(rhs);
    SparseMatrix mat = DynamicSparseMatrix(DynamicSparseMatrix(m_grid));
    std::vector<double> pressures(0,m_grid.sizeI() * m_grid.sizeJ() * m_grid.sizeK());
    if(!m_pcgSolver.solve(mat,m_grid,pressures,rhs))
    {
        //TODO report iteration limit exhaustion
    }

    double scale = m_grid.getDt() / (m_grid.getFluidDensity() * m_grid.getSideLength());

    for (int i = m_grid.sizeI(); i >= 0; i--)
    {
        for (int j = m_grid.sizeJ(); j >= 0; j--)
        {
            for (int k = m_grid.sizeK(); k >= 0; k--)
            {
                //U part
                if(m_grid.getMaterial(i-1,j,k) == FluidCell::FLUID || m_grid.getMaterial(i,j,k) == FluidCell::FLUID)
                {
                    if(m_grid.getMaterial(i-1,j,k) == FluidCell::SOLID || m_grid.getMaterial(i,j,k) == FluidCell::SOLID)
                    {
                        m_grid.at(i,j,k).setU(0);//Solids are stationary
                    }
                    else
                    {
                        m_grid.at(i,j,k).U() -= scale * (pressures[m_grid.linearIndex(i,j,k)] - pressures[m_grid.linearIndex(i-1,j,k)]);
                    }
                }
                else
                {
                    m_grid.at(i,j,k).setUnknownU();
                }

                //V part
                if(m_grid.getMaterial(i,j-1,k) == FluidCell::FLUID || m_grid.getMaterial(i,j,k) == FluidCell::FLUID)
                {
                    if(m_grid.getMaterial(i,j-1,k) == FluidCell::SOLID || m_grid.getMaterial(i,j,k) == FluidCell::SOLID)
                    {
                        m_grid.at(i,j,k).setV(0);//Solids are stationary
                    }
                    else
                    {
                        m_grid.at(i,j,k).V() -= scale * (pressures[m_grid.linearIndex(i,j,k)] - pressures[m_grid.linearIndex(i,j-1,k)]);
                    }
                }
                else
                {
                    m_grid.at(i,j,k).setUnknownV();
                }

                //W part
                if(m_grid.getMaterial(i,j,k-1) == FluidCell::FLUID || m_grid.getMaterial(i,j,k) == FluidCell::FLUID)
                {
                    if(m_grid.getMaterial(i,j,k-1) == FluidCell::SOLID || m_grid.getMaterial(i,j,k) == FluidCell::SOLID)
                    {
                        m_grid.at(i,j,k).setW(0);//Solids are stationary
                    }
                    else
                    {
                        m_grid.at(i,j,k).W() -= scale * (pressures[m_grid.linearIndex(i,j,k)] - pressures[m_grid.linearIndex(i,j,k-1)]);
                    }
                }
                else
                {
                    m_grid.at(i,j,k).setUnknownW();
                }
            }
        }
    }
}

void FlipSolver::calcRhs(std::vector<double> &rhs)
{
    double scale = 1/m_grid.getSideLength();

    for (int i = 0; i < m_grid.sizeI(); i++)
    {
        for (int j = 0; j < m_grid.sizeJ(); j++)
        {
            for (int k = 0; k < m_grid.sizeK(); k++)
            {
                if (m_grid.getMaterial(i,j,k) == FluidCell::FLUID)
                {
                    rhs[m_grid.linearIndex(i,j,k)] = -scale * (m_grid.getU(i+1,j,k) - m_grid.getU(i,j,k)
                                                              +m_grid.getV(i,j+1,k) - m_grid.getV(i,j,k)
                                                              +m_grid.getW(i,j,k+1) - m_grid.getW(i,j,k));
                }
            }
        }
    }
}
