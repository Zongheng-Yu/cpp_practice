/*
 * TestExercise.cpp
 *
 *  Created on: 2018?4?16?
 *      Author: zonyu
 */
#include "gtest/gtest.h"
#include "twoSum.hpp"
#include <vector>

using std::vector;

TEST(twoSum, workingOk)
{
    vector<int> ref{0, 1};
    ASSERT_EQ(ref, twoSum(vector<int>{2, 7, 11, 15}, 9));
}
