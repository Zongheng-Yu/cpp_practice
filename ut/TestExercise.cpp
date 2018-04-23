/*
 * TestExercise.cpp
 *
 *  Created on: 2018?4?16?
 *      Author: zonyu
 */
#include <vector>
#include "gtest/gtest.h"
#include "twoSum.hpp"
#include "longestSubstring.hpp"


using std::vector;

TEST(twoSum, workingOk)
{
    vector<int> ref{0, 1};
    ASSERT_EQ(ref, twoSum(vector<int>{2, 7, 11, 15}, 9));
}

TEST(lengthOfLongestSubstring, workingOk)
{
    ASSERT_EQ(3, lengthOfLongestSubstring("abcabcbb"));
    ASSERT_EQ(1, lengthOfLongestSubstring("bbbbb"));
    ASSERT_EQ(3, lengthOfLongestSubstring("pwwkew"));
}
