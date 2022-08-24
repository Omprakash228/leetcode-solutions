#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public: 
    static vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        vector<vector<int>> result(r, vector<int>(c));
        queue<int> q;

        int row = mat.size();
        int col = mat[0].size();

        if(row*col != r*c)
            return mat;

        for(vector<int> row : mat) {
            for(int e : row) {
                q.push(e);
            }
        }

        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                result[i][j] = q.front();
                q.pop();
            }
        }

        return result;
    }
};


int main() {
    vector<vector<int>> mat{{1, 2}, {3, 4}};

    vector<vector<int>> result = Solution::matrixReshape(mat, 2, 4);

    for(vector<int> r : result) {
        for(int e : r) {
            cout << e << ' ';
        }
        cout << endl;
    }

    return 0;
}