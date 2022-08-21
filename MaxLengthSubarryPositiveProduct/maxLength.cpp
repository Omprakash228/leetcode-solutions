#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static int getMaxLen(vector<int>& nums) {
        int firstNeg = -1, firstZero = -1, totalNeg = 0, res = 0;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] < 0) {
                totalNeg++;
                if(firstNeg == -1) firstNeg = i;
            }
            if(nums[i] == 0) {
                firstNeg = -1;
                firstZero = i;
                totalNeg = 0;
            }

            if(totalNeg % 2 == 0) res = max(i - firstZero, res);
            else res = max(i - firstNeg, res);
        }

        return res;
    }
};

int main() {
    vector<int> nums{1, -2, -3, 4};

    cout << Solution::getMaxLen(nums);
    return 0;                                                               
}