/*
 * TestSort.cpp
 *
 *  Created on: 2018?4?23?
 *      Author: zonyu
 */
#include <string>
#include "gtest/gtest.h"
#include "sort.hpp"
#include "SortableClass.hpp"

using std::string;

TEST(testSort, giveSortedDataTestSortWorksOk)
{
    std::vector<int> input{1, 2, 3, 3, 4, 5, 6, 7, 8, 9};
    std::vector<int> ref{1, 2, 3, 3, 4, 5, 6, 7, 8, 9};
    sort(input);
    ASSERT_EQ(ref, input);
}

TEST(testSort, giveReversedSortedDataTestSortWorksOk)
{
    std::vector<int> input{9, 8, 7, 6, 5, 4, 3, 3, 2, 1};
    std::vector<int> ref{1, 2, 3, 3, 4, 5, 6, 7, 8, 9};
    sort(input);
    ASSERT_EQ(ref, input);
}

TEST(testSort, giveUnSortedDataTestSortWorksOk)
{
    std::vector<int> input{8, 9, 7, 5, 6, 3, 1, 2, 3, 4};
    std::vector<int> ref{1, 2, 3, 3, 4, 5, 6, 7, 8, 9};
    sort(input);
    ASSERT_EQ(ref, input);
}

TEST(testSort, giveVectorWithSameElementsTestSortWorksOk)
{
    std::vector<int> input{2, 2, 2, 2, 2};
    std::vector<int> ref{2, 2, 2, 2, 2};
    sort(input);
    ASSERT_EQ(ref, input);
}

TEST(testSort, giveEmptyInputTestSortWorksOk)
{
    std::vector<int> input{};
    std::vector<int> ref{};
    sort(input);
    ASSERT_EQ(ref, input);
}


TEST(testSort, giveStringVectorTestSortWorksOk)
{
    std::vector<string> input{string{"Mercury"}, string{"Venus"},
                           string{"Earth"}, string{"Mars"},
                           string{"Jupiter"}, string{"Saturn"},
                           string{"Uranus"}, string{"Neptune"}};
    std::vector<string> ref{"Earth", "Jupiter", "Mars", "Mercury",
                            "Neptune", "Saturn", "Uranus", "Venus"};
    sort(input);
    ASSERT_EQ(ref, input);
}

TEST(testSort, giveSortableClassTestSortWorksOk)
{
    std::vector<SortableClass> input{8, 9, 7, 5, 6, 3, 1, 2, 3, 4};
    std::vector<SortableClass> ref{1, 2, 3, 3, 4, 5, 6, 7, 8, 9};
    sort(input);
    ASSERT_EQ(ref, input);
}
