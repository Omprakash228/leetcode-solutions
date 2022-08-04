#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    static int maxLength(vector<int> &nums)
    {
        if (nums.size() < 2)
            return nums.size();
        int prevDiff = nums[1] - nums[0];
        int result = prevDiff == 0 ? 1 : 2;

        for (int i = 2; i < nums.size(); i++)
        {
            int currDiff = nums[i] - nums[i - 1];
            if ((prevDiff < 0 && currDiff >= 0) || (prevDiff >=0 && currDiff < 0))
            {
                result++;
                prevDiff = currDiff;
            }
        }
        return result;
    }
};

int main()
{
    vector<int> nums{3, 3, 3, 2, 5};
    cout << Solution::maxLength(nums);
    return 0;
}