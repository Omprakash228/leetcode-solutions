#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    static bool isCovered(vector<vector<int>> &ranges, int left, int right)
    {
        for (int i = left; i <= right; i++)
        {
            bool covered = false;
            for (vector<int> range : ranges)
            {
                if (range[0] <= i && i <= range[1])
                {
                    covered = true;
                    break;
                }
            }
            if (covered == false)
            {
                return false;
            }
        }

        return true;
    }
};

int main()
{
    vector<vector<int>> ranges{{1, 2}, {3, 4}, {5, 6}};

    cout << Solution::isCovered(ranges, 2, 8) << "\n";
    return 0;
}