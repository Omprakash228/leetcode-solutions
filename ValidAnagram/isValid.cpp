#include <iostream>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    static bool isAnagram(string s, string t)
    {
        unordered_map<char, int> freq;
        int sSize = s.length();
        int tSize = t.length();

        if (sSize != tSize)
            return false;

        for (int i = 0; i < sSize; i++)
        {
            freq[s[i]]++;
            freq[t[i]]--;
        }

        for (char c : s)
        {
            if (freq[c] != 0)
                return false;
        }

        return true;
    }
};

int main()
{
    string s = "anagram";
    string t = "nagram";

    cout << Solution::isAnagram(s, t);
    return 0;
}