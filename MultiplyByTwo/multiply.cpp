#include <iostream>
#include <set>
#include <vector>
using namespace std;

class Solution
{
public:
    static int findValue(vector<int> &nums, int original)
    {
        set<int> numSet;
        for (int n : nums)
            numSet.insert(n);

        while (numSet.count(original) != 0)
        {
            original *= 2;
        }

        return original;
    }
};

int main()
{
    vector<int> nums{2, 7, 9};
    cout << Solution::findValue(nums, 3);

    return 0;
}