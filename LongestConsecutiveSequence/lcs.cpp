#include <iostream>
#include <unordered_set>
#include <vector>
#include <numeric>

using namespace std;

class Solution
{
public:
    static int longestConsecutive(vector<int> &nums)
    {
        int result = 0;
        unordered_set<int> numSet;
        for (int n : nums)
        {
            numSet.insert(n);
        }

        for (int n : nums)
        {
            if (numSet.find(n - 1) == numSet.end())
            {
                int currNum = n;
                int seqLength = 1;

                while (numSet.find(currNum + 1) != numSet.end())
                {
                    currNum += 1;
                    seqLength += 1;
                }
                result = max(result, seqLength);
            }
        }
        return result;
    }
};

int main()
{
    vector<int> nums{0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    cout << Solution::longestConsecutive(nums);

    return 0;
}
