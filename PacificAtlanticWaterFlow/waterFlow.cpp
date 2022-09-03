#include <iostream>
#include <vector>

using namespace std;

class Solution {
    vector<vector<int>> directions{{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    int rows;
    int cols;
    vector<vector<int>> landHeights;
public:
    vector<vector<int>> waterFlow(vector<vector<int>> heights) {
        vector<vector<int>> result;
        if(heights.size() == 0 || heights[0].size() == 0) {
            return result;
        }

        rows = heights.size();
        cols = heights[0].size();
        landHeights = heights;
        vector<vector<bool>> pacific(rows, vector<bool>(cols));
        vector<vector<bool>> atlantic(rows, vector<bool>(cols));

        for(int i = 0; i < rows; i++) {
            dfs(i, 0, pacific);
            dfs(i, cols - 1, atlantic);
        }

        for(int i = 0; i < cols; i++) {
            dfs(0, i, pacific);
            dfs(rows - 1, i, atlantic);
        }

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(atlantic[i][j] && pacific[i][j]) {
                    result.push_back({i, j});
                }
            }
        }

        return result;             
    }

    void dfs(int r, int c, vector<vector<bool>>& reachable) {
        reachable[r][c] = true;
        for(vector<int> dir : directions) {
            int newRow = r + dir[0];
            int newCol = c + dir[1];

            if(newRow < 0 || newRow >= rows || newCol < 0 || newCol >= cols)
                continue;
            
            if(reachable[newRow][newCol])
                continue;
            
            if(landHeights[newRow][newCol] < landHeights[r][c]) 
                continue;
            
            dfs(newRow, newCol, reachable);
        }
    }
};

int main() {
    vector<vector<int>> heights{{1, 2, 2, 3, 5},
                                {3, 2, 3, 4, 4}, 
                                {2, 4, 5, 3, 1},
                                {6, 7, 1, 4, 5},
                                {5, 1, 1, 2, 4}};

    Solution s;
    vector<vector<int>> result = s.waterFlow(heights);

    for(vector<int> row : result) {
        for(int e : row) {
            cout << e << " ";
        }
        cout << endl;
    }
    return 0;
}