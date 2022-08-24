#include <iostream>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    static bool canConstruct(string ransomNote, string magazine)
    {
        unordered_map<char, int> magFreq;

        for (char m : magazine)
        {
            magFreq[m]++;
        }

        for (char r : ransomNote)
        {
            if (!magFreq[r])
            {
                return false;
            }
            magFreq[r]--;
        }

        return true;
    }
};

int main()
{
    string ransomNote = "aaa";
    string magazine = "aab";

    cout << Solution::canConstruct(ransomNote, magazine);
    return 0;
}