/*
 * TestLambda.cpp
 *
 *  Created on: 2018?8?15?
 *      Author: zonyu
 */
#include <gtest/gtest.h>
#include <algorithm>
#include <vector>

namespace{
using List = std::vector<int>;
// Generate a list with content which is start with startValue,
List genListWithContent(int startValue, int step, int count)
{
    List list{};
    return std::move(list);
}

// Genereate a list whose content is from userData but not in exclude
List getListValueNotIn(const List &userData, const List &exclude)
{
    List list{};
    std::for_each(userData.cbegin(), userData.cend(),
                  [&](const auto& item)
                  {
                      std::find
                      list.emplace_back(item);

                  });
    return std::move(list);
}

// Check the input list contains all odd number
bool areAllItemsOdd(const List &list)
{
    ...
}

/* Sort and merge two lists.
*  When removeDuplicate is set true, the returned list keeps no duplicated items. If set false,
*  the result list contains all items in both list even there are have duplicated items.
*  When isAscend is set true, both list is sorted in ascending order, otherwise in descending order.
*/
List sortAndMerge(const List &list1, const List &list2, bool isAscend,  bool removeDuplicate)
{
   ...
}
class LambdaExerciseTest: public ::testing::Test
{
};

TEST_F(LambdaExerciseTest, GenListWithContent)
{
    List target = {2, 5, 8, 11, 14, 17, 20};
    EXPECT_EQ(target, genListWithContent(2, 3, 7));
}

TEST_F(LambdaExerciseTest, GetListValueNotIn)
{
    List target = {1, 2, 5, 7, 17};
    EXPECT_EQ(target, getListValueNotIn({1, 2, 5, 7, 9, 8, 20, 17}, {14, 8, 20, 9}));
}

TEST_F(LambdaExerciseTest, AreAllItemsOdd)
{
    EXPECT_EQ(true, areAllItemsOdd({1, 3, 5, 7, 9}));
    EXPECT_EQ(false, areAllItemsOdd({1, 3, 5, 7, 9, 10}));
}

TEST_F(LambdaExerciseTest, SortAndMerge)
{
    List list1 = {2, 7, 4, 8};
    List list2 = {3, 9, 8, 6, 3};
    List target = {2, 3, 3, 4, 6, 7, 8, 8, 9};
    EXPECT_EQ(target, sortAndMerge(list1, list2, true, false));
    target = {2, 3, 4, 6, 7, 8, 9};
    EXPECT_EQ(target, sortAndMerge(list1, list2, true, true));
    target = {9, 8, 8, 7, 6, 4, 3, 3, 2};
    EXPECT_EQ(target, sortAndMerge(list1, list2, false, false));
    target = {9, 8, 7, 6, 4, 3, 2};
    EXPECT_EQ(target, sortAndMerge(list1, list2, false, true));
}
}





