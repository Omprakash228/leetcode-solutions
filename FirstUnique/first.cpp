#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    static int firstUniqChar(string s) {
        unordered_map<char, int> freq;

        for(char c : s) {
            freq[c]++;
        }

        for(int i = 0; i < s.length(); i++) {
            if(freq[s[i]] == 1)
                return i;
        }

        return -1;
    }
};

int main() {
    string s = "aabb";
    cout << Solution::firstUniqChar(s);
    return 0;
}