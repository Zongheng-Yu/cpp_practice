#include <string>
#include "gtest/gtest.h"
#include "compare.hpp"
#include "Blob.hpp"

using std::string;

extern template int compare(const int&, const int&);

extern template int compare(const char* const& p1, const char* const& p2);


TEST(testCompareInt, workingOk)
{
    ASSERT_GT(compare(1, 0), 0);
    ASSERT_EQ(compare(1, 1), 0);
    ASSERT_LT(compare(1, 2), 0);
}

TEST(testCompareString, workingOk)
{
    ASSERT_GT(compare(string("def"), string("abc")), 0);
    ASSERT_EQ(compare(string("abc"), string("abc")), 0);
    ASSERT_LT(compare(string("abc"), string("def")), 0);
}

TEST(testCompareCharArray, workingOk)
{
    ASSERT_GT(compare("def", "abcd"), 0);
    /** can't compare same length of const char array.
        int comapre(const char[5], const char[5]) suites both
        template <typename T> int compare(const T& a, const T& b) and
        template <size_t N, size_t M> int compare(const char (&str1)[N], const char (&str2)[M])
        with same priority
    **/
    //ASSERT_EQ(compare("abcd", "abcd"), 0);
    ASSERT_LT(compare("abcd", "def"), 0);
}

TEST(testCompareCharPointer, workingOk)
{
    const char* p1 = "abc";
    const char* p2 = "def";
    ASSERT_GT(compare(p2, p1), 0);
    ASSERT_EQ(compare(p1, p1), 0);
    ASSERT_LT(compare(p1, p2), 0);
}

TEST(testBlob, testBlob)
{
    Blob<int> blob1;
    ASSERT_EQ(0, blob1.size());
    ASSERT_THROW(blob1.pop_back();, std::out_of_range);
    ASSERT_THROW(blob1.back();, std::out_of_range);
    Blob<int> blob2{1, 2, 3};
    ASSERT_EQ(3, blob2.size());
    blob2.pop_back();
    ASSERT_EQ(2, blob2.size());
    ASSERT_EQ(2, blob2.back());
    ASSERT_EQ(1, blob2[0]);
    ASSERT_EQ(2, blob2[1]);
}
