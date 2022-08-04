#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution
{
public:
    static vector<vector<int>> intervalIntersection(vector<vector<int>> &firstList, vector<vector<int>> &secondList)
    {
        vector<vector<int>> result;
        int i = 0;
        int j = 0;

        while (i < firstList.size() && j < secondList.size())
        {
            int l = max(firstList[i][0], secondList[j][0]);
            int h = min(firstList[i][1], secondList[j][1]);

            if(l <= h) 
                result.push_back({l, h});

            if (firstList[i][1] > secondList[j][1])
                j++;
            else
                i++;

            cout << "i: " << i << " j: " << j << endl;
        }

        return result;
    }
};

int main()
{
    vector<vector<int>> firstList{{4, 6}, {7, 8}, {10, 17}};
    vector<vector<int>> secondList{{5, 10}};

    vector<vector<int>> result = Solution::intervalIntersection(firstList, secondList);

    for (vector<int> e : result)
    {
        cout << e[0] << " " << e[1] << endl;
    }

    return 0;
}