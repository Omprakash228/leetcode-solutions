#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static int maxScoreSightseeingPair(vector<int>& nums) {
        int maxIndex = 0;
        int score = 0;
        int tempScore = 0;

        for(int i = 1; i < nums.size(); i++) {
            tempScore = max(nums[maxIndex] + nums[i] + maxIndex - i, tempScore);
            score = max(score, tempScore);

            if(nums[i] + i > nums[maxIndex] + maxIndex) maxIndex = i;
        }

        return score;
    }
};

int main() {
    vector<int> nums{7, 2, 6, 6, 9, 4, 3};
    cout << Solution::maxScoreSightseeingPair(nums);
    return 0;
}