#include <gtest/gtest.h>

#include "dynamicsparsematrix.h"

class DynamicSparseMatrixTest : public ::testing::Test {
public:
    DynamicSparseMatrixTest() :
        zeroMatrix(0),
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

    DynamicSparseMatrix zeroMatrix;
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

    diag100Matrix = DynamicSparseMatrix(100);

    for(int i = 0; i < 100; i++)
    {
        EXPECT_EQ(square3Matrix.getValue(i,i),i);
    }
}
