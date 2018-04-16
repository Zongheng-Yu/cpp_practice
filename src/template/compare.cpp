#include "compare.hpp"
#include <string>

using std::string;

template int compare(const int&, const int&);
template int compare(const string&, const string&);

//An template specification to template int compare(const int&, const int&);
template <>
int compare(const char* const& p1, const char* const& p2)
{
    std::cout << "compare version 3 called" << std::endl;
    return strcmp(p1, p2);
}
