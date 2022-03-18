#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
    public:
        static bool containsDuplicate(vector<int>& nums)
        {
            unordered_set<int> unique;
            for(int i = 0; i < nums.size(); i++) {
                if(unique.find(nums[i]) != unique.end()) {
                    return true;
                }
                unique.insert(nums[i]);
            }
            return false;
        }
};

int main() {
    vector<int> nums{1,2,3,1,4};
    cout << Solution::containsDuplicate(nums);
    return 0;
}