#include <gtest/gtest.h>

#include "fluidgrid.h"

static const int smallSizeI = 200;
static const int smallSizeJ = 150;
static const int smallSizeK = 100;

class FluidGridTest : public ::testing::Test {
public:
    FluidGridTest() :
        gridSmall(smallSizeI,smallSizeJ,smallSizeK),
        gridSmallNeg(smallSizeI,smallSizeJ,smallSizeK)
    {
        for(int i = 0; i < smallSizeI; i++)
        {
            for(int j = 0; j < smallSizeJ; j++)
            {
                for(int k = 0; k < smallSizeK; k++)
                {
                    gridSmall.setCellVelocity(i,j,k,FluidGrid::U,i*10+j*smallSizeI + k*smallSizeI*smallSizeJ + 1);
                    gridSmall.setCellVelocity(i,j,k,FluidGrid::V,i*10+j*smallSizeI + k*smallSizeI*smallSizeJ + 2);
                    gridSmall.setCellVelocity(i,j,k,FluidGrid::W,i*10+j*smallSizeI + k*smallSizeI*smallSizeJ + 3);
                    gridSmall.setMaterial(i,j,k,FluidCell::FLUID);

                    gridSmallNeg.setCellVelocity(i,j,k,FluidGrid::NU,i*10+j*smallSizeI + k*smallSizeI*smallSizeJ + 1);
                    gridSmallNeg.setCellVelocity(i,j,k,FluidGrid::NV,i*10+j*smallSizeI + k*smallSizeI*smallSizeJ + 2);
                    gridSmallNeg.setCellVelocity(i,j,k,FluidGrid::NW,i*10+j*smallSizeI + k*smallSizeI*smallSizeJ + 3);
                    gridSmallNeg.setMaterial(i,j,k,FluidCell::FLUID);
                }
            }
        }
    }

protected:
    void SetUp() override {}

    void TearDown() override {}

    FluidGrid gridSmall;
    FluidGrid gridSmallNeg;
};

TEST_F(FluidGridTest,GridReadTest)
{
    for(int i = 0; i < smallSizeI; i++)
    {
        for(int j = 0; j < smallSizeJ; j++)
        {
            for(int k = 0; k < smallSizeK; k++)
            {
                EXPECT_EQ(gridSmall.getCellVelocity(i,j,k,FluidGrid::U),i*10+j*smallSizeI + k*smallSizeI*smallSizeJ + 1);
                EXPECT_EQ(gridSmall.getCellVelocity(i,j,k,FluidGrid::V),i*10+j*smallSizeI + k*smallSizeI*smallSizeJ + 2);
                EXPECT_EQ(gridSmall.getCellVelocity(i,j,k,FluidGrid::W),i*10+j*smallSizeI + k*smallSizeI*smallSizeJ + 3);
                EXPECT_EQ(gridSmall.getMaterial(i,j,k),FluidCell::FLUID);

                EXPECT_EQ(gridSmallNeg.getCellVelocity(i,j,k,FluidGrid::NU),i*10+j*smallSizeI + k*smallSizeI*smallSizeJ + 1);
                EXPECT_EQ(gridSmallNeg.getCellVelocity(i,j,k,FluidGrid::NV),i*10+j*smallSizeI + k*smallSizeI*smallSizeJ + 2);
                EXPECT_EQ(gridSmallNeg.getCellVelocity(i,j,k,FluidGrid::NW),i*10+j*smallSizeI + k*smallSizeI*smallSizeJ + 3);
                EXPECT_EQ(gridSmallNeg.getMaterial(i,j,k),FluidCell::FLUID);
            }
        }
    }
}
