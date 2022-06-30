#include <iostream>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    static int LengthOfLongestSubstring(string s)
    {
        int a_pointer = 0;
        int b_pointer = 0;
        int m = 0;
        unordered_set<char> chars;

        while (b_pointer < s.length())
        {
            if (chars.find(s[b_pointer]) == chars.end())
            {
                chars.insert(s[b_pointer]);
                b_pointer++;
                m = max((int)chars.size(), m);
            }
            else
            {
                chars.erase(s[a_pointer]);
                a_pointer++;
            }
        }
        return m;
    }
};

int main()
{
    int length = Solution::LengthOfLongestSubstring("baeacd");
    cout << length << endl;
    return 0;
}