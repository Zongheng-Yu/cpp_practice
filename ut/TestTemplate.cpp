#include <string>
#include "gtest/gtest.h"
#include "compare.hpp"
#include "Blob.hpp"

using std::string;

extern template int compare(const int&, const int&);

extern template int compare(const char* const& p1, const char* const& p2);


TEST(testCompareInt, testLarger)
{
    ASSERT_GT(compare(1, 0), 0);
}

TEST(testCompareInt, testEqual)
{
    ASSERT_EQ(compare(1, 1), 0);
}

TEST(testCompareInt, testLess)
{
    ASSERT_LT(compare(1, 2), 0);
}


TEST(testCompareString, testLarger)
{
    ASSERT_GT(compare(string("def"), string("abc")), 0);
}

TEST(testCompareString, testEqual)
{
    ASSERT_EQ(compare(string("abc"), string("abc")), 0);
}

TEST(testCompareString, testLess)
{
    ASSERT_LT(compare(string("abc"), string("def")), 0);
}


TEST(testCompareCharArray, testLarger)
{
    ASSERT_GT(compare("def", "abcd"), 0);
}

TEST(testCompareCharArray, testEqual)
{
    /** can't compare same length of const char array.
        int comapre(const char[5], const char[5]) suites both
        template <typename T> int compare(const T& a, const T& b) and
        template <size_t N, size_t M> int compare(const char (&str1)[N], const char (&str2)[M])
        with same priority
    **/
    //ASSERT_EQ(compare("abcd", "abcd"), 0);
}

TEST(testCompareCharArray, testLess)
{
    ASSERT_LT(compare("abcd", "def"), 0);
}


TEST(testCompareCharPointer, testLarger)
{
    const char* p1 = "abc";
    const char* p2 = "def";
    ASSERT_GT(compare(p2, p1), 0);
}

TEST(testCompareCharPointer, testEqual)
{
    const char* p1 = "abc";
    ASSERT_EQ(compare(p1, p1), 0);
}

TEST(testCompareCharPointer, testLess)
{
    const char* p1 = "abc";
    const char* p2 = "def";
    ASSERT_LT(compare(p1, p2), 0);
}

TEST(testBlob, testBlob)
{
    Blob<int> blob1;
    ASSERT_EQ(0, blob1.size());

}
