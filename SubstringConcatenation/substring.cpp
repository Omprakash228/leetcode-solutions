#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    unordered_map<string, int> wordCount;
    int wL;
    int ssL;
    int k;

    vector<int> findSubstring(string s, vector<string> words) {
        int n = s.length();
        k = words.size();
        wL = words[0].length();
        ssL = wL * k;

        for(string word: words) {
            wordCount[word]++;
        }

        vector<int> result;

        for(int i = 0; i < n - ssL + 1; i++) {
            if(check(s, i)) 
                result.push_back(i);
        }

        return result;
    }

    bool check(string s, int i) {
        unordered_map<string, int> remaining = wordCount;
        int count = 0;

        for(int j = i; j < i + ssL; j += wL) {
            string ss = s.substr(j, wL);
            cout << "substring: " << ss << endl;
            if(remaining[ss] != 0) {
                count++;
                remaining[s]--;
            } else {
                break;
            }
        }

        return count == k;
    }
};

int main() {
    vector<string> words{"foo", "bar"};
    string s = "barfoothefoobarman";
    Solution sol;
    vector<int> result = sol.findSubstring(s, words);

    for(int i : result) {
        cout << i << " ";
    }

    return 0;
}