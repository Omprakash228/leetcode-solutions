#include <iostream>
#include <vector>

using namespace std;

class NumArray {
    vector<int> dp;
public:
    NumArray(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return; 
        dp = vector<int>(n+1, 0);

        for(int i = 0; i < n; i++) {
            dp[i+1] = dp[i] + nums[i];
        }
    }

    int sumRange(int left, int right) {
        return dp[right+1] - dp[left];
    }
};

int main() {
    vector<int> nums{-2, 0, 3, -5, 2, -1};

    NumArray* obj = new NumArray(nums);
    cout << obj->sumRange(2, 5);

    return 0;
}