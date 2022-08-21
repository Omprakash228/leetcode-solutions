#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static int maxProduct(vector<int>& nums) {
        int mi, m, res;
        mi = m = res = nums[0];

        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] < 0) swap(mi, m);
            mi = min(nums[i], nums[i] * mi);
            m = max(nums[i], nums[i] * m);
            res = max(res, m);
        }

        return res;
    }
};

int main() {
    vector<int> nums{2, 3, -2, 4};
    cout << Solution::maxProduct(nums);
    return 0;
}