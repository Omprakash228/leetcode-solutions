#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<set<int>> rows(9), cols(9), block(9);

        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] == '.') continue;

                int val = board[i][j] - '0';
                if(rows[i].count(val) || cols[j].count(val) || block[(i/3)*3+j/3].count(val))
                    return false;
                
                rows[i].insert(val);
                cols[j].insert(val);
                block[(i/3)*3+j/3].insert(val);
            }
        }
        return true;
    }
};

int main() {
    vector<vector<char>> board{{'5','3','.','.','7','.','.','.','.'}
,{'6','.','.','1','9','5','.','.','.'}
,{'.','9','8','.','.','.','.','6','.'}
,{'8','.','.','.','6','.','.','.','3'}
,{'4','.','.','8','.','3','.','.','1'}
,{'7','.','.','.','2','.','.','.','6'}
,{'.','6','.','.','.','.','2','8','.'}
,{'.','.','.','4','1','9','.','.','5'}
,{'.','.','.','.','8','.','.','7','9'}};
    Solution s;

    cout << s.isValidSudoku(board);
    return 0;
}