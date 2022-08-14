#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public: 
    static vector<int> findSubstring(string s, vector<string> words) {
        int n = s.length();
        int w = words.size();
        int wL = words[0].length();

        vector<int> result{};
        unordered_map<string, int> freq;

        for(string word: words) {
            freq[word]++;
        }

        for(int i = 0; i < wL; i++) {
            unordered_map<string, int> seen;

            int left = i;
            int currLen = 0;

            for(int r = left; r <= n - wL; r += wL) {
                string temp = s.substr(r, wL);
                if(freq[temp] == 0) {
                    seen.clear();
                    currLen = 0;
                    left = r + wL;
                } else {
                    seen[temp]++;
                    currLen++;
                    while(seen[temp] > freq[temp]) {
                        string temp1 = s.substr(left, wL);
                        seen[temp1]--;
                        currLen--;
                        left += wL;
                    }
                }

                if(currLen == w) {
                    result.push_back(left);
                    seen[s.substr(left, wL)]--;
                    currLen--;
                    left += wL;
                }
            }
        }
        return result;
    }
};

int main() {
    vector<string> words{"word", "good", "best", "word"};
    string s = "wordgoodgoodgoodbestword";
    
    vector<int> result = Solution::findSubstring(s, words);

    for(int i : result) {
        cout << i << " ";
    }

    return 0;
}