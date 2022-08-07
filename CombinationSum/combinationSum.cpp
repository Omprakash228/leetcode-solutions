#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static int combinationSum(vector<int>& nums, int target) {
        vector<unsigned int> dp(target+1, 0);
        dp[0] = 1;

        for(int i = 1; i <= target; i++) {
            for(int num: nums) {
                if(num > i)
                    continue;
                
                dp[i] += dp[i - num];
            }
        }

        return dp[target];
    }
};

int main() {
    vector<int> nums{1, 2, 3};
    cout << Solution::combinationSum(nums, 4) << "\n";
    return 0;
}