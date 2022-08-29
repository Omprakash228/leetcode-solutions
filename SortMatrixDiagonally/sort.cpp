#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    static vector<vector<int>> diagonalSort(vector<vector<int>> &mat)
    {
        if (mat.size() <= 1 || mat[0].size() <= 1)
            return mat;
        int rows = mat.size();
        int cols = mat[0].size();

        for (int i = rows - 2; i >= 0; i--)
        {
            sortDiagonal(i, 0, rows, cols, mat);
        }

        for (int i = cols - 2; i >= 1; i--)
        {
            sortDiagonal(0, i, rows, cols, mat);
        }

        return mat;
    }

    static void sortDiagonal(int r, int c, int rows, int cols, vector<vector<int>> &mat)
    {
        int i = r, j = c;
        vector<int> temp;
        while (i < rows && j < cols)
        {
            temp.push_back(mat[i++][j++]);
        }
        sort(temp.begin(), temp.end());
        int k = 0;
        i = r;
        j = c;
        while (i < rows && j < cols && k < temp.size())
        {
            mat[i++][j++] = temp[k++];
        }
    }
};

int main()
{
    vector<vector<int>> mat{{11, 25, 66, 1, 69, 7},
                            {23, 55, 17, 45, 15, 52},
                            {75, 31, 36, 44, 58, 8},
                            {22, 27, 33, 25, 68, 4},
                            {84, 28, 14, 11, 5, 50}};

    vector<vector<int>> result = Solution::diagonalSort(mat);

    for (vector<int> row : result)
    {
        for (int elem : row)
        {
            cout << elem << " ";
        }
        cout << "\n";
    }

    return 0;
}