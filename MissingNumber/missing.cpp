#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    static int missingNumber(vector<int> &nums)
    {
        int n = nums.size();
        int total = (n * (n + 1)) / 2;

        for (int i : nums)
        {
            total -= i;
        }

        return total;
    }
};

int main()
{
    vector<int> nums{3, 0, 1};
    cout << Solution::missingNumber(nums) << endl;

    return 0;
}