#include <gtest/gtest.h>

int equi(int inputArr[], int arrayLen)
{
    if(arrayLen == 0){
        return -1;
    }
    int sums[arrayLen+1];
    // Find equilibrium index of inputArr
    sums[0] = 0;
    for(int i=0; i<arrayLen; i++){
        sums[i+1] = sums[i]+inputArr[i];
    }
    int eqIndex = 0;
    while(eqIndex<arrayLen){
        if(sums[eqIndex] == (sums[arrayLen] - sums[eqIndex+1]))
            return eqIndex;
        eqIndex++;
    }
    return -1;
}

TEST(EquiTest, EmptyArrayReturnsZero)
{
    const int arrayLen = 0;
    int inputArr[arrayLen] = {};
    int equiIndex = equi(inputArr, arrayLen);
    int expectedEquiIndex = -1;
    ASSERT_EQ(expectedEquiIndex, equiIndex);
}

TEST(EquiTest, SampleArray)
{
    const int arrayLen = 4;
    int inputArr[arrayLen] = {2, -3, 4, -2};
    int equiIndex = equi(inputArr, arrayLen);
    int expectedEquiIndex = 1;
    ASSERT_EQ(expectedEquiIndex, equiIndex);
}
TEST(EquiTest, SampleArrayWithNoEquIndex)
{
    const int arrayLen = 3;
    int inputArr[arrayLen] = {2, -3, 4};
    int equiIndex = equi(inputArr, arrayLen);
    int expectedEquiIndex = -1;
    ASSERT_EQ(expectedEquiIndex, equiIndex);
}