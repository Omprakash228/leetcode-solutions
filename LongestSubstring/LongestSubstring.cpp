#include<iostream>
#include<string>
#include<unordered_set>

using namespace std;


int lengthOfLongestSubstring(string s) {
    int resultLength = 0;
    unordered_set<char> entries;
    
    for(int i = 0; i < s.length(); i++)
    {
        cout << s[i] << "\n";
        cout << entries.size() << "\n";
        unordered_set<char>::iterator it = entries.find(s[i]);
        if(it != entries.end()){
            resultLength = resultLength > entries.size() ? resultLength : entries.size();
            entries.erase(entries.begin(), it);
            entries.erase(entries.begin());
        } 
        
        entries.insert(s[i]);
        
    }
    resultLength = resultLength > entries.size() ? resultLength : entries.size();
    cout << "Result: ";
    cout << resultLength;
    return resultLength;
}

int main() {
    string s = "pewwkew";
    lengthOfLongestSubstring(s);
    return 0;
}