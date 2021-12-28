#include <gtest/gtest.h>

#include "dynamicsparsematrix.h"

class DynamicSparseMatrixTest : public ::testing::Test {
public:
    DynamicSparseMatrixTest() :
        square3Matrix(3),
        diag100Matrix(100)
    {
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                square3Matrix.setValue(i,j,j+i*3);
            }
        }

        for(int i = 0; i < 100; i++)
        {
            diag100Matrix.setValue(i,i,i);
        }
    }

protected:
    void SetUp() override {}

    void TearDown() override {}

    DynamicSparseMatrix square3Matrix;
    DynamicSparseMatrix diag100Matrix;
};

TEST_F(DynamicSparseMatrixTest,DynamicMatrixReading)
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            EXPECT_EQ(square3Matrix.getValue(i,j),j+i*3);
        }
    }

    for(int i = 0; i < 100; i++)
    {
        for(int j = 0; j < 100; j++)
        {
            if(i == j)
            {
                EXPECT_EQ(diag100Matrix.getValue(i,j),i);
            }
            else
            {
                EXPECT_EQ(diag100Matrix.getValue(i,j),0);
            }
        }
    }
}

TEST_F(DynamicSparseMatrixTest,DynamicMatrixElementCount)
{
    EXPECT_EQ(square3Matrix.elementCount(),9);
    EXPECT_EQ(diag100Matrix.elementCount(),100);
}
