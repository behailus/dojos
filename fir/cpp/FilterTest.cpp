#include "gtest/gtest.h"
#include "VectorComparator.hpp"
#include <vector>
#include <math.h>

using namespace std;

vector<float> FirFilter(vector<float> input)
{
    vector<float> coefs  = {0.5, 0.3, 0.2, 0.1};
    vector<float> output = {};
    int s = input.size();
    for(int i=0; i<s+3; i++){
        float total = 0;
        for(int j=0; j<coefs.size();j++){
            int n = i-j;
            float in = (n>=0 && n<s)?input.at(n):0;
            total+=(coefs.at(j)*in);
        }
        output.push_back(total);
    }
    return output;
}

TEST(FilterTest, ZeroInput)
{
    vector<float> input     = {0};
    vector<float> output    = FirFilter(input);
    vector<float> refOutput = {0, 0, 0, 0};

    ASSERT_TRUE(CompareVectors(refOutput, output));
}

TEST(FilterTest, ImpulseInput)
{
    vector<float> input     = {1};
    vector<float> output    = FirFilter(input);
    vector<float> refOutput = {0.5, 0.3, 0.2, 0.1};

    ASSERT_TRUE(CompareVectors(refOutput, output));
}

TEST(FilterTest, OutputLengthWithShortInput)
{
    vector<float> input     = {1, 1};
    vector<float> output    = FirFilter(input);
    vector<float> refOutput = {0.5, 0.8, 0.5, 0.3, 0.1};

    ASSERT_TRUE(CompareVectors(refOutput, output));
}

TEST(FilterTest, OutputLengthWithLongInput)
{
    vector<float> input     = {1, 1, 1, 1, 1};
    vector<float> output    = FirFilter(input);
    vector<float> refOutput = {0.5, 0.8, 1.0, 1.1, 1.1, 0.6, 0.3, 0.1};

    ASSERT_TRUE(CompareVectors(refOutput, output));
}

