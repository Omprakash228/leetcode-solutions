#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static int removeElement(vector<int> nums, int val) {
        for(int i = 0; i < nums.size();) {
            if(nums[i] == val) {
                nums.erase(nums.begin() + i);
            } else {
                i++;
            }
        }
        return nums.size();
    }
};

int main() {
    vector<int> nums{3, 1, 1, 3};
    cout << Solution::removeElement(nums, 3);

    return 0;
}