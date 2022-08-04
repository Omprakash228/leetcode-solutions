#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    static int maxArea(int h, int w, vector<int> &horizontalCuts, vector<int> &verticalCuts)
    {
        int area = 0;
        int hMax = maxDifference(0, h, horizontalCuts);
        int vMax = maxDifference(0, w, verticalCuts);
        return (1LL * hMax * vMax) % (1000000007);
    }

    static int maxDifference(int l, int h, vector<int> &cuts)
    {
        sort(cuts.begin(), cuts.end());
        int diff = cuts[0] - l;
        for (int i = 0; i < cuts.size(); i++)
        {
            if (i != cuts.size() - 1)
                diff = max(diff, cuts[i + 1] - cuts[i]);
            else
                diff = max(diff, h - cuts[i]);
        }
        return diff;
    }
};

int main()
{
    int h = 1000000000;
    int w = 1000000000;
    vector<int> horizontalCuts{2};
    vector<int> verticalCuts{2};
    cout << Solution::maxArea(h, w, horizontalCuts, verticalCuts);
    return 0;
}
