#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    static vector<int> getSquares(vector<int> &nums)
    {
        vector<int> result(nums.size(), 0);
        int l = 0;
        int h = nums.size() - 1;

        for(int i = nums.size() - 1; i >= 0; i--) {
            if(abs(nums[l]) > nums[h]) {
                result[i] = nums[l] * nums[l];
                l++;
            }
            else {
                result[i] = nums[h] * nums[h];
                h--;
            }
        }
        return result;
    }
};

int main()
{
    vector<int> nums{-5, -3, -2, -1};
    vector<int> squares = Solution::getSquares(nums);
    for (int i : squares)
    {
        cout << i << " ";
    }
    return 0;
}