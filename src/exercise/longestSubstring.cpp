#include <string>
#include <set>

using std::string;
using std::set;

int lengthOfLongestSubstring(const string s)
{
    int longest = 0;
    for (auto iter1 = s.cbegin(); iter1 != s.cend(); ++iter1) {
        auto curSet = set<char>{*iter1};
        for (auto iter2 = iter1 +1; iter2 != s.cend(); ++iter2) {
            if (curSet.find(*iter2) != curSet.end()) {
                break;
            }
            curSet.insert(*iter2);
        }
        auto size = curSet.size();
        if (size > longest) {
            longest = size;
        }
    }
    return longest;
}
