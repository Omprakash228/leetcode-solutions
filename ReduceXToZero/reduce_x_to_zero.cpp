#include <iostream>
#include <vector>
#include <unordered_map>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

class Solution {
    public:
        static int reduceXToZero(vector<int>& nums, int x) {
            int target = -x;
            for(int i : nums) target += i;

            if (target == 0) return nums.size();

            unordered_map<int, int> sumIndex;
            sumIndex.insert({0, -1});
            int long_sub_length = 0;
            int steps = INT_MAX;
            int curr_sum = 0;

            for(int i = 0; i < nums.size(); i++) {
                curr_sum += nums[i];
                sumIndex.insert({curr_sum, i});

                unordered_map<int, int>::iterator match = sumIndex.find(curr_sum - target);

                if(match != sumIndex.end()) {
                    long_sub_length = i - match->second;
                    int curr_step = nums.size() - long_sub_length;

                    // cout << long_sub_length << " " << steps << " " << curr_step << endl;
                    steps = min(steps, curr_step);
                }
            }

            return long_sub_length == 0 ? -1 : steps;
        }
};

int main() {
    vector<int> nums {5,2, 3, 1, 1};
    int steps = Solution::reduceXToZero(nums, 5);
    cout << steps << endl;
    return 0;
}