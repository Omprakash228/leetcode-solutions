#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    static int match(string s, vector<string> &words)
    {
        int matches = 0, k = s.size();
        unordered_map<string,int> stringMap;

        for(int i=0;i<words.size();i++){
            stringMap[words[i]]++;
        }

        for(auto st: stringMap){
           int i = 0,j = 0;
            string m = st.first;
            int p = m.size();
            while(i<k && j<p){
                if(s[i] == m[j]){
                    j++;
                }
                i++;
            }
            if(j == p){
                matches += st.second;
            }
        }
        return matches;
    }
};

int main()
{
    vector<string> words{"a", "abc", "acd", "ace", "abcde"};
    cout << Solution::match("abcde", words) << "\n";
    return 0;
}