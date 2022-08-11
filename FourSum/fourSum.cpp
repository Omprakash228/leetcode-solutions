#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    static vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());

        return solve(nums, target, 0, 4);
    }

    static vector<vector<int>> solve(vector<int> &nums, long target, int start, int k)
    {
        vector<vector<int>> result;
        long avg = target / k;

        if (nums[start] > avg || avg > nums[nums.size() - 1])
            return result;

        if (k == 2)
        {
            return twoSum(nums, target, start);
        }

        for (int i = start; i <= nums.size() - k; i++)
        {
            if (i == start || nums[i] != nums[i - 1])
            {
                vector<vector<int>> interResult = solve(nums, target - nums[i], i + 1, k - 1);

                for (vector<int> r : interResult)
                {
                    r.push_back(nums[i]);
                    result.push_back(r);
                }
            }
        }

        return result;
    }

    static vector<vector<int>> twoSum(vector<int> nums, long target, int start)
    {
        int l = start;
        int h = nums.size() - 1;
        vector<vector<int>> result;

        while (l < h)
        {
            int sum = nums[l] + nums[h];

            if (sum < target || (l > start && nums[l] == nums[l - 1]))
            {
                l++;
            }
            else if (sum > target || (h < nums.size() - 1 && nums[h] == nums[h + 1]))
            {
                h--;
            }
            else
            {
                result.push_back({nums[l], nums[h]});
                l++;
                h--;
            }
        }

        return result;
    }
};

int main()
{
    vector<int> nums{1, 0, -1, 0, -2, 2};
    vector<vector<int>> result = Solution::fourSum(nums, 0);

    for (vector<int> r : result)
    {
        for (int i : r)
        {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}