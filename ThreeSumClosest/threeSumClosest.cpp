#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#include<algorithm>

using namespace std;

class Solution {
    public:
        static int closest(vector<int>& nums, int target) {
            int near = INT_MAX;
            int n = nums.size();

            sort(nums.begin(), nums.end());

            for(int i = 0; i <= n-3; i++) {
                if(i == 0 || (i > 0 && nums[i-1] != nums[i])) {
                    int l = i+1;
                    int h = n-1;
                    int sum = 0;
                    while(l < h) {
                        cout << nums[i] << " " << nums[l] << " " << nums[h] << endl;
                        sum = nums[i] + nums[l] + nums[h];
                        if(sum == target) return sum;
                        if(abs(target-sum) < abs(target - near)) 
                            near = sum;
                        if(sum < target) 
                            l++;
                        else 
                            h--;
                    }

                    cout << "sum: " << sum << endl;
                    cout << "abs: " << abs(target-sum) << endl;
                    cout << "near: " << near << endl;
                    
                    cout << "newNear: " << near << endl;
                }
            }
            return near;
        }
};

int main() {
    vector<int> nums{4, 0, 5, -5, 3, 3, 0, -4, -5};
    cout << Solution::closest(nums, -2) << endl;

    return 0;
}