#include <iostream>
#include <vector>

using namespace std;

class Solution {
public: 
    static bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, false);
        dp[n-1] = true;
        
        for(int i = n - 2; i >= 0; i--) {
            for(int j = i + 1; j < n && j <= i + nums[i]; j++) {
                if(dp[j]){
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[0];
    }

    static bool cleverCanJump(vector<int>& nums) {
        int index = nums.size() - 1;
        for(int i = nums.size() - 1; i >= 0; i--) {
            if(nums[i] + i >= index) {
                index = i;
            }
        }

        return index == 0;
    }
};

int main() {
    vector<int> nums{3, 2, 1, 0, 4};
    cout << Solution::cleverCanJump(nums);
    return 0;
}