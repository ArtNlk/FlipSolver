#include <gtest/gtest.h>

#include "fluidgrid.h"

static const int smallSizeI = 200;
static const int smallSizeJ = 150;
static const int smallSizeK = 100;

class FluidGridTest : public ::testing::Test {
public:
    FluidGridTest() :
        gridSmall(smallSizeI,smallSizeJ,smallSizeK,1,1,1),
        gridSmallNeg(smallSizeI,smallSizeJ,smallSizeK,1,1,1)
    {
        for(int i = 0; i < smallSizeI; i++)
        {
            for(int j = 0; j < smallSizeJ; j++)
            {
                for(int k = 0; k < smallSizeK; k++)
                {
                    gridSmall.setU(i,j,k,i*10+j*smallSizeI + k*smallSizeI*smallSizeJ + 1);
                    gridSmall.setV(i,j,k,i*10+j*smallSizeI + k*smallSizeI*smallSizeJ + 2);
                    gridSmall.setW(i,j,k,i*10+j*smallSizeI + k*smallSizeI*smallSizeJ + 3);
                    gridSmall.setMaterial(i,j,k,FluidCell::FLUID);
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
                EXPECT_EQ(gridSmall.getU(i,j,k),i*10+j*smallSizeI + k*smallSizeI*smallSizeJ + 1);
                EXPECT_EQ(gridSmall.getV(i,j,k),i*10+j*smallSizeI + k*smallSizeI*smallSizeJ + 2);
                EXPECT_EQ(gridSmall.getW(i,j,k),i*10+j*smallSizeI + k*smallSizeI*smallSizeJ + 3);
                EXPECT_EQ(gridSmall.getMaterial(i,j,k),FluidCell::FLUID);
            }
        }
    }
}
