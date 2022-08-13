#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static int searchInsert(vector<int>& nums, int target) {
        return binarySearch(nums, target, 0, nums.size() - 1);
    }

    static int binarySearch(vector<int>& nums, int target, int low, int high) {
        if(low > high)
            return low;

        int mid = (high + low) / 2;

        if(nums[mid] > target)
            high = mid - 1;
        else if(nums[mid] < target)
            low = mid + 1;
        else 
            return mid;

        return binarySearch(nums, target, low, high);
    }
};

int main() {
    vector<int> nums{1, 3, 4, 6};
    cout << Solution::searchInsert(nums, 5);
    return 0;
}