#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int deleteAndEarn(vector<int> &nums)
    {
        vector<int> elements{};
        unordered_map<int, int> points;

        for (int n : nums)
        {
            if (points[n] == 0)
                elements.push_back(n);
            points[n] += n;
        }

        sort(elements.begin(), elements.end());

        int twoBack = 0;
        int oneBack = points[elements[0]];

        for (int i = 1; i < elements.size(); i++)
        {
            int temp = oneBack;
            if (elements[i] == elements[i - 1] + 1)
            {
                oneBack = max(oneBack, twoBack + points[elements[i]]);
            }
            else
            {
                oneBack += points[elements[i]];
            }

            twoBack = temp;
        }

        return oneBack;
    }
};

int main()
{
    vector<int> nums{2, 2, 3, 3, 3, 4};
    Solution s;
    cout << s.deleteAndEarn(nums);
    return 0;
}