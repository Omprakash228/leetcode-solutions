#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    static int removeDuplicates(vector<int> &nums)
    {
        int count = 1;
        int insptr = 1;
        int low = 0;
        int high = 1;

        while (high < nums.size())
        {
            if (nums[low] == nums[high])
            {
                high++;
            }
            else
            {
                count++;
                nums[insptr] = nums[high];
                insptr++;
                low = high;
                high++;
            }
        }
        return count;
    }

    static int removeDuplicates2(vector<int>& nums) {
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        return nums.size();
    }
};

int main()
{
    vector<int> nums{0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    cout << Solution::removeDuplicates2(nums) << endl;

    for (int i : nums)
    {
        cout << i << " ";
    }
    return 0;
}