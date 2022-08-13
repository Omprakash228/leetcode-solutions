#include <iostream>

using namespace std;

class Solution
{
public:
    static int length(string s)
    {
        int count;

        for (int i = 0; i < s.length(); i++)
        {
            if (i == 0 && s[i] != ' ')
                count = 1;

            if (i > 0 && s[i] != ' ')
            {
                if (s[i - 1] == ' ')
                    count = 1;
                else
                    count++;
            }
        }

        return count;
    }

    static int betterLength(string s) {
        int count = 0;

        for(int i = s.size() - 1; i >= 0; i--) {
            if(s[i] != ' ')
                ++count;
            else if(count)
                return count;
        }
        return count;
    }
};

int main()
{
    string s = "  fly to the  moon  ";
    cout << Solution::length(s) << endl;
    return 0;
}