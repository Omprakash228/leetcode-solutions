#include <iostream>
#include <vector>

using namespace std;

class NumArray {
    vector<int> dp;
public:
    NumArray(vector<int>& nums)  {
        int n = nums.size();
        if(n == 0) return;

        dp = vector<int>(n+1, 0);

        for(int i = 0; i < n; i++) {
            dp[i+1] = dp[i] + nums[i];
        }
    }

    void update(int index, int val) {
        if(index+1 > dp.size()) return;
        int curr = dp[index+1] - dp[index];

        for(int i = index+1; i < dp.size(); i++) {
            dp[i] = dp[i] - curr + val;
        }
    }

    int sumRange(int left, int right) {
        return dp[right+1] - dp[left];
    }
};

int main() {
    vector<int> nums{1, 3, 5};
    NumArray* obj = new NumArray(nums);
    cout << obj->sumRange(0, 2) << endl;
    obj->update(1, 2);
    cout << obj->sumRange(0, 2);
    return 0;
}