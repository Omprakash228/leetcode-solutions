#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    static int maxSubarray(vector<int> &nums)
    {
        int tempMaxSum, maxSum, sum, tempMinSum, minSum;
        tempMaxSum = maxSum = sum = tempMinSum = minSum = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {
            tempMaxSum = max(nums[i], tempMaxSum + nums[i]);
            maxSum = max(maxSum, tempMaxSum);
            sum += nums[i];

            tempMinSum = min(nums[i], tempMinSum + nums[i]);
            minSum = min(minSum, tempMinSum);
        }

        return minSum == sum ? maxSum : max(maxSum, sum - minSum);
    }
};

int main()
{
    vector<int> nums{-3, -2, -3};

    cout << Solution::maxSubarray(nums);
    return 0;
}