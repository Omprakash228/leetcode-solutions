#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);

        vector<int> noHead{};
        vector<int> noTail{};

        for(int i = 0; i < nums.size(); i++) {
            if(i != 0) 
                noHead.push_back(nums[i]);
            if(i != nums.size() - 1) 
                noTail.push_back(nums[i]);
        }

        return max(solve(noHead), solve(noTail));
    }

    static int solve(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);

        vector<int> dp(n + 1, 0);
        dp[n - 1] = nums[n - 1];
        dp[n - 2] = nums[n - 2];
        int m = max(dp[n - 1], dp[n - 2]);

        for(int i = n - 3; i >= 0; i--) {
            dp[i] = max(nums[i] + dp[i + 2], nums[i] + dp[i + 3]);
            m = max(m, dp[i]);
        }

        return m;
    }
};

int main() {
    vector<int> nums{2, 3, 2};
    cout << Solution::rob(nums);
    return 0;
}