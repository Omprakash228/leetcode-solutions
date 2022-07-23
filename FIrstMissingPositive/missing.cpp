#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    static int firstMissingPositive(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> presence(n, -1);

        for (int i : nums)
        {
            if (i > 0 && i <= n)
            {
                presence[i - 1]++;
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (presence[i] == -1)
                return i + 1;
        }
        return n + 1;
    }
};

int main()
{
    vector<int> nums{1, 2, 3, 4};
    cout << Solution::firstMissingPositive(nums) << endl;
    return 0;
}