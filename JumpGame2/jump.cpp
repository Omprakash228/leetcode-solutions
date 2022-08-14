#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    static int jump(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, 10002);
        dp[n - 1] = 0;

        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = i + 1; j < n & j <= nums[i] + i; j++)
            {
                dp[i] = min(dp[i], dp[j] + 1);
            }
        }

        return dp[0];
    }
};

int main()
{
    vector<int> nums{2, 3, 0, 1, 4};
    cout << Solution::jump(nums);
    return 0;
}