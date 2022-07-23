#include <iostream>
#include <string.h>

using namespace std;

class Solution
{
public:
    static bool backspaceCompare(string s, string t)
    {
        return removeBackspace(s) == removeBackspace(t);
    }

    static string removeBackspace(string s)
    {
        string result = "";
        for (char e : s)
        {
            if (e == '#' && result.length() != 0)
                result = result.substr(0, result.length() - 1);
            if (e != '#')
                result += e;
        }
        cout << result << endl;
        return result;
    }
};

int main()
{
    cout << Solution::backspaceCompare("y#fo##f", "y#f#o##f") << endl;
    return 0;
}