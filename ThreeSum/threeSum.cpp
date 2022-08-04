#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    static vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> result;
        int n = nums.size();
        if (n < 3)
            return result;

        sort(nums.begin(), nums.end());

        for (int i = 0; i <= n - 3; i++)
        {
            if (i == 0 || (i > 0 && nums[i] != nums[i - 1]))
            {
                int l = i + 1;
                int h = n - 1;
                while (l < h)
                {
                    int sum = nums[i] + nums[l] + nums[h];
                    if (sum == 0)
                    {
                        result.push_back({nums[i], nums[l], nums[h]});
                        while (l < h && nums[l] == nums[l + 1])
                            l++;
                        while (l < h && nums[h] == nums[h - 1])
                            h--;
                        l++;
                        h--;
                    }
                    else if (sum > 0)
                        h--;
                    else
                        l++;
                }
            }
        }
        return result;
    }
};

int main()
{
    vector<int> nums{-2, 0, 1, 1, 2};
    vector<vector<int>> result = Solution::threeSum(nums);
    for (vector<int> s : result)
    {
        cout << s[0] << " " << s[1] << " " << s[2] << endl;
    }

    return 0;
}