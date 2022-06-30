#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    public: 
        static int minMoves(vector<int>& nums) {
            sort(nums.begin(), nums.end());
            int result = 0;
            int n = nums.size();
            int median = n%2 == 0 ? ((nums[n/2] + nums[n/2-1]) / 2) : nums[n/2];

            for(int i = 0; i < n; i++) {
                result += abs(nums[i] - median);
            }
            return result;
        }
};

int main() {
    vector<int> nums{1, 10, 2, 9};
    cout << Solution::minMoves(nums) << endl;
    return 0;
}