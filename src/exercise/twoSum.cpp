#include <vector>

using std::vector;

vector<int> twoSum(const vector<int>& nums, int target)
{
    for (int i = 0; i < nums.size() - 1; i++)
    {
        for (int j = i + 1; i < nums.size(); i++)
        {
            if (nums[i] + nums[j] == target)
            {
                return vector<int>{i, j};
            }
        }
    }
    return vector<int>{};
}

