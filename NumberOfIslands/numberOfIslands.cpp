#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        static void callDFS(vector<vector<char>>& grid, int i, int j) {
            if(i >= 0 && i < grid.size() && j >= 0 && j < grid[i].size() && grid[i][j] != '0') {
                grid[i][j] = '0';
                callDFS(grid, i-1, j);
                callDFS(grid, i+1, j);
                callDFS(grid, i, j-1);
                callDFS(grid, i, j+1);
            }
        }

        static void printVector(vector<vector<char>>& grid) {
            for(int i = 0 ; i < grid.size(); i++) {
                for(int j = 0; j < grid[i].size(); j++) {
                    cout << grid[i][j] << "\t";
                }
                cout << endl;
            }
        }


        static int numIslands(vector<vector<char>>& grid) {
            int count = 0;

            for(int i = 0; i < grid.size(); i++) {
                for(int j = 0; j < grid[i].size(); j++){
                    if(grid[i][j] == '1'){
                        count += 1;
                        callDFS(grid, i, j);
                    }
                }
            }
            return count;
        }
};

int main() {
    vector<vector<char>> grid{{'1', '1', '0', '0', '0'}, 
    {'1', '1', '0', '0', '0'},
    {'0', '0', '1', '0', '0'},
    {'0', '0', '0', '1', '1'}};

    cout << Solution::numIslands(grid);
    return 0;
}