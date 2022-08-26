#include <iostream>

using namespace std;

class Solution
{
public:
    static int secondsToRemoveOccurences(string s)
    {
        int count = 0;
        int len = s.length();
        bool isChanged = true;

        while (isChanged)
        {
            int i = 0;
            isChanged = false;
            while (i < len - 1)
            {
                if (s[i] == '0' && s[i + 1] == '1')
                {
                    swap(s[i++], s[i++]);
                    isChanged = true;
                }
                else
                    i++;
            }
            count += isChanged;
        }
        return count;
    }
};

int main()
{
    string s = "0110101";
    cout << Solution::secondsToRemoveOccurences(s);
    return 0;
}