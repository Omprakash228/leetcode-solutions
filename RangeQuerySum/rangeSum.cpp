#include <iostream>
#include <vector>

using namespace std;

class NumMatrix {
    vector<vector<int>> dp;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        if(!rows || !cols) return;
        dp = vector<vector<int>>(rows+1, vector<int>(cols+1, 0));

        for(int r = 0; r < rows; r++) {
            for(int c = 0; c < cols; c++) {
                dp[r+1][c+1] = dp[r+1][c] + dp[r][c+1] + matrix[r][c] - dp[r][c];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return dp[row2+1][col2+1] - dp[row1][col2+1] - dp[row2+1][col1] + dp[row1][col1];
    }
};

int main() {
    vector<vector<int>> matrix{{3, 0, 1, 4, 2}, 
                               {5, 6, 3, 2, 1},
                               {1, 2, 0, 1, 5}, 
                               {4, 1, 0, 1, 7},
                               {1, 0, 3, 0, 5}};

    NumMatrix* obj = new NumMatrix(matrix);

    cout << obj->sumRegion(2, 1, 4, 3);

    return 0;
}