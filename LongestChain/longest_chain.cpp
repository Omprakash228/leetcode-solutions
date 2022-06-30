#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    public:
        static int longestStrChain(vector<string>& words) {
            unordered_map<string, int> chain;
            sort(words.begin(), words.end(), [](string &l, string &r){ return l.size() < r.size();});
            int result = 1;

            for(string s: words) {
                chain[s] = 1;
                for(int i = 0; i < s.size(); i++) {
                    string sub = s.substr(0, i) + s.substr(i+1, s.size());
                    unordered_map<string, int>::iterator match = chain.find(sub);
                    if(match != chain.end()) {
                        chain[s] = max(chain[s], match->second + 1);
                        result = max(result, chain[s]);
                    }
                }
            }

            return result;
        }
};

int main() {
    vector<string> words{"abcd", "dbqca"};
    cout << Solution::longestStrChain(words) << endl;
    return 0;
}