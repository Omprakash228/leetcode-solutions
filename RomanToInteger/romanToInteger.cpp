#include<iostream>
#include<unordered_map>
using namespace std;

class Solution {
    public:
        static int romanToInteger(string s) {
            unordered_map<char, int> symbols{{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

            int num = 0;

            for(int i = 0; i < s.length(); i++) {
                if(i < s.length() - 1
                && ((s[i] == 'I' && (s[i+1] == 'V' || s[i+1] == 'X'))
                || (s[i] == 'X' && (s[i+1] == 'L' || s[i+1] == 'C'))
                || (s[i] == 'C' && (s[i+1] == 'D' || s[i+1] == 'M'))
                )) {
                    num += symbols[s[i+1]] - symbols[s[i]];
                    i += 1;
                } else {
                    num += symbols[s[i]];
                }
            }
            return num;
        }
};

int main() {
    cout << Solution::romanToInteger("XC") << endl;
    return 0;
}

