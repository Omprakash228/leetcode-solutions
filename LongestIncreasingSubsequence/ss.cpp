#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution
{
public:
    static int length(vector<int> &nums)
    {
        vector<int> dp(nums.size(), 1);

        for (int i = 1; i < nums.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        int result = 0;

        for (int i = 0; i < dp.size(); i++)
        {
            result = max(result, dp[i]);
        }

        return result;
    }

    static int length2(vector<int>& nums) {
        set<int> c;

        for(int n : nums) {
            if(!c.count(n)) {
                c.insert(n);
                set<int>::iterator it = c.find(n);
                it++;
                if(it != c.end()) {
                    c.erase(it);
                }
            }
        }

        return c.size();
    }
};

int main()
{
    vector<int> nums{0, 1, 0, 3, 2, 3};
    cout << Solution::length2(nums) << "\n";
    return 0;
}