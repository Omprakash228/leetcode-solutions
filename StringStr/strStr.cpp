#include <iostream>

using namespace std;

class Solution
{
public:
    static int strStr(string haystack, string needle)
    {
        if (needle.empty())
            return 0;
        int h = haystack.length();
        int n = needle.length();
        int nP;

        for (int i = 0; i <= (h - n); i++)
        {
            int s = i, e = i;
            nP = 0;
            while (needle[nP] == haystack[e])
            {
                nP++;
                e++;
                if (nP == n)
                {
                    return s;
                }
            }
        }
        return -1;
    }
};

int main()
{
    cout << Solution::strStr("cream", "ame");
    return 0;
}