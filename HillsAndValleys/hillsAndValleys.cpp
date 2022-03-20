#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public: 
        static int countHillValley(vector<int>& nums) {
            int hill = 0;
            int valley = 0;

            for(int i = 0; i < nums.size(); i++) {
                int left = i - 1;
                int right = i + 1;
                while (left > i && nums[i] == nums[left])
                    left--;
                while (right < i && nums[i] == nums[right])
                    right++;
                if(nums[left] < nums[i] && nums[right] < nums[i] && nums[i] != nums[left] && nums[i] != nums[right]) {
                    cout << "Hill:" << "\t" << left << "\t" << right << endl;
                    hill++;
                }
                if(nums[left] > nums[i] && nums[right] > nums[i] && nums[i] != nums[left] && nums[i] != nums[right]) {
                    cout << "Valley:" << "\t" << left << "\t" << right << endl;
                    valley++;
                }
            }

            cout << hill << "\t" << valley;
            return max(hill,valley);
        }
};

int main() {
    vector<int> nums{2,4,1,1,6,5};
    cout << Solution::countHillValley(nums);
    return 0;
}