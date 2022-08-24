#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    static bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int r = matrix.size();
        int c = matrix[0].size();
        int sr = 0;

        for (int i = 0; i < r; i++)
        {
            if (matrix[i][0] <= target && matrix[i][c - 1] >= target)
                sr = i;
        }

        cout << sr << endl;

        int l = 0;
        int h = c - 1;

        while (l <= h)
        {
            int m = (l + h) / 2;
            if (matrix[sr][m] == target)
                return true;
            else if (matrix[sr][m] < target)
                l = m + 1;
            else
                h = m - 1;
        }

        return false;
    }
};

int main()
{
    vector<vector<int>> matrix{{1}};

    cout << Solution::searchMatrix(matrix, 1);

    return 0;
}