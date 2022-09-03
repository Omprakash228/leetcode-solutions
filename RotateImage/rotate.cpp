#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    static void rotate(vector<vector<int>>& matrix) {
        transpose(matrix);
        reflect(matrix);
    }

    static void transpose(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                int temp = matrix[j][i];
                matrix[j][i] = matrix[i][j];
                matrix[i][j] = temp;
            }
        }
    }

    static void reflect(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n/2; j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[i][n - j - 1];
                matrix[i][n - j - 1] = temp;
            }
        }
    }
};

int main() {
    vector<vector<int>> matrix{{5, 1, 9, 11}, 
                                {2, 4, 8, 10}, 
                                {13, 3, 6, 7}, 
                                {15, 14, 12, 16}};

    Solution::rotate(matrix);

    for(vector<int> row : matrix) {
        for(int e : row) {
            cout << e << " ";
        }
        cout << endl;
    }
}