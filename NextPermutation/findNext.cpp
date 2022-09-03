#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 2;

        while(i >= 0 && nums[i+1] <= nums[i]) {
            i--;
        }

        if(i >= 0) {
            int j = nums.size() - 1;
            while(nums[j] <= nums[i]) {
                j--;
            }
            swap(nums, i, j);
        }
        reverse(nums, i+1);
    }

    static void swap(vector<int>& nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    static void reverse(vector<int>& nums, int i) {
        int l = i, h = nums.size() -1;
        while(l < h) {
            swap(nums, l, h);
            l++;
            h--;
        }
    }
};

int main() {
    vector<int> nums{1, 2, 3};

    Solution::nextPermutation(nums);
    for(int i : nums) {
        cout << i << " ";
    }   
    return 0;
}