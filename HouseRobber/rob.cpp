#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    static int rob(vector<int> &nums)
    {
        int n = nums.size();

        if(n == 1)
            return nums[0];

        vector<int> dp(n + 1, 0);
        dp[n - 1] = nums[n - 1];
        dp[n - 2] = nums[n - 2];
        int result = max(dp[n - 1], dp[n - 2]);

        for (int i = n - 3; i >= 0; i--)
        {
            dp[i] = max(nums[i] + dp[i + 2], nums[i] + dp[i + 3]);
            result = max(result, dp[i]);
        }

        return result;
    }
};

int main()
{
    vector<int> nums{2, 7, 1, 3, 9};
    cout << Solution::rob(nums);
    return 0;
}