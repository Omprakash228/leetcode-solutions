#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

class Solution
{
public:
    static int maxSubArray(vector<int> &nums)
    {
        int sum = INT_MIN;

        for (int i = 0; i < nums.size(); i++)
        {
            int tempSum = 0;
            for (int j = i; j < nums.size(); j++)
            {
                tempSum += nums[j];
                sum = max(sum, tempSum);
            }
        }

        return sum;
    }

    static int fastMax(vector<int> &nums)
    {
        int sum = nums[0];
        int tempSum  = nums[0];

        for(int i = 1; i < nums.size(); i++)
        {
            tempSum = max(nums[i], nums[i] + tempSum);
            sum = max(sum, tempSum);
        }

        return sum;
    }
};

int main()
{
    vector<int> nums{5, -3, 5};

    cout << Solution::fastMax(nums);
    return 0;
}