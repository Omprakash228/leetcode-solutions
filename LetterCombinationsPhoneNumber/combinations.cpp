#include <iostream>
#include <vector>

using namespace std;

class Solution {
    vector<vector<string>> m{
        {"a", "b", "c"},
        {"d", "e", "f"},
        {"g", "h", "i"},
        {"j", "k", "l"},
        {"m", "n", "o"},
        {"p", "q", "r", "s"},
        {"t", "u", "v"},
        {"w", "x", "y", "z"}};
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        for(int i = 0; i < digits.length(); i++) {
            int n = digits[i] - 48;
            vector<string> letters = m[n - 2];
            if(result.size() == 0) {
                result = letters;
                continue;
            } 
            
            vector<string> temp;
            for(string r : result) {
                for(string l : letters) {
                    temp.push_back(r+l);
                }
            }
            result = temp;
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<string> result = s.letterCombinations("234");

    for(string r: result) {
        cout << r << "\n";
    }
    return 0;
}