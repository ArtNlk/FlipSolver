#include <gtest/gtest.h>

#include <vector>

#include "sparsematrix.h"

class SparseMatrixTest : public ::testing::Test {
public:
    SparseMatrixTest() :
        square5Matrix(DynamicSparseMatrix(0)),
        identity5Matrix(DynamicSparseMatrix(0)),
        diag100Matrix(DynamicSparseMatrix(0)),
        fiveOnes(5,1),
        hundredOnes(100,1),
        oneToFive(5),
        oneToHundred(100)
    {
        DynamicSparseMatrix tempSquare5matrix = DynamicSparseMatrix(5);
        DynamicSparseMatrix tempIdentity5matrix = DynamicSparseMatrix(5);
        DynamicSparseMatrix tempDiag100matrix = DynamicSparseMatrix(100);
        for(int i = 0; i < 5; i++)
        {
            for(int j = 0; j < 5; j++)
            {
                tempSquare5matrix.setValue(i,j,j);
            }
            oneToFive[i] = i+1;
        }

        for(int i = 0; i < 5; i++)
        {
            tempIdentity5matrix.setValue(i,i,1);
        }

        for(int i = 0; i < 100; i++)
        {
            tempDiag100matrix.setValue(i,i,i);
            oneToHundred[i] = i + 1;
        }

        this->square5Matrix = SparseMatrix(tempSquare5matrix);
        this->identity5Matrix = SparseMatrix(tempIdentity5matrix);
        this->diag100Matrix = SparseMatrix(tempDiag100matrix);
    }

protected:
    void SetUp() override {}

    void TearDown() override {}

    SparseMatrix square5Matrix;
    SparseMatrix identity5Matrix;
    SparseMatrix diag100Matrix;

    std::vector<double> fiveOnes;
    std::vector<double> hundredOnes;
    std::vector<double> oneToFive;
    std::vector<double> oneToHundred;
};

TEST_F(SparseMatrixTest,SpraseMatrixReadingTest)
{
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            EXPECT_EQ(square5Matrix.getValue(i,j),j);
        }
    }

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            if(i == j)
            {
                EXPECT_EQ(identity5Matrix.getValue(i,j),1);
            }
            else
            {
                EXPECT_EQ(identity5Matrix.getValue(i,j),0);
            }
        }
    }
}
