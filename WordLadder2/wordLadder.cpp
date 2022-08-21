#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public: 
    unordered_map<string, vector<string>> g;
    unordered_set<string> words;
    string e;

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> wordList) {
        vector<vector<string>> result;
        vector<unordered_set<char>> posChar(beginWord.length());
        e = endWord;
        
        int wL = beginWord.length();

        for(int i = 0; i < beginWord.length(); i++) {
            for(string word: wordList) {
                posChar[i].insert(word[i]);
            }
        }

        for(string word : wordList) {
            words.insert(word);
        }

        solve(posChar, beginWord);

        for(auto x: g) {
            cout << x.first << ":" << endl;
            for(string s : x.second) {
                cout << s << " ";
            }
            cout << "\n\n"; 
        }

        return result;        
    }

    void solve(vector<unordered_set<char>>& posChar, string beginWord) {
        int wL = beginWord.length();
        for(int i = 0; i < wL; i++) {
            for(unordered_set<char>::iterator it = posChar[i].begin(); it != posChar[i].end(); it++) {
                if(*it != beginWord[i]) {
                    string temp = beginWord;
                    temp = temp.substr(0, i) + *it + temp.substr(i+1, wL - i - 1);
                    unordered_map<string, vector<string>>::iterator gIt = g.find(temp);
                    if(gIt == g.end() && words.count(temp) != 0 && beginWord != e) {
                        g[beginWord].push_back(temp);
                        g.insert({temp, {}});
                    }
                }
            }

            for(string s : g[beginWord]) {
                solve(posChar, s);
            }
        }
    }


};

int main() {
    vector<string> wordList{"hot", "dot", "dog", "lot", "log", "cog"};
    
    Solution s;
    vector<vector<string>> result = s.findLadders("hit", "cog", wordList);


    for(vector<string> t : result) {
        for(string s : t) {
            cout << s << " ";
        }

        cout << endl;
    }

    return 0;
}