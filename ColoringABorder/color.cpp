#include <iostream>
#include <vector>

using namespace std;

class Solution {
    vector<vector<int>> directions{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    vector<vector<int>> g;
    vector<vector<int>> visited;
    int rows;
    int cols;
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r, int c, int color) {
        rows = grid.size();
        cols = grid[0].size();

        g = grid;
        visited = vector<vector<int>>(rows, vector<int>(cols, 0));
        dfs(grid, r, c, color);

        return g;
    }

    void dfs(vector<vector<int>>& grid, int r, int c, int color) {
        int count = 0;
        visited[r][c] = 1;
        vector<vector<int>> toVisit;
        for(vector<int> dir : directions) {
            int nr = r + dir[0];
            int nc = c + dir[1];

            if(nr < 0 || nr >= rows || nc < 0 || nc >= cols)
                continue;

            if(grid[nr][nc] == grid[r][c]) {
                count++;
                toVisit.push_back({nr, nc});
            }
        }
        if(count < 4) {
            g[r][c] = color;
        }

        for(vector<int> e : toVisit) {
            if(visited[e[0]][e[1]] == 0)
                dfs(grid, e[0], e[1], color);
        }
    }
};

int main() {
    vector<vector<int>> grid{{1, 1, 1, 1}, 
                            {1, 1, 1, 1}, 
                            {1, 1, 1, 1},
                            {1, 1, 1, 1}};
    Solution* s = new Solution();

    vector<vector<int>> result = s->colorBorder(grid, 0, 0, 3);

    for(vector<int> row : result) {
        for(int ele : row) {
            cout << ele << " ";
        }
        cout << "\n";
    }

    return 0;
}