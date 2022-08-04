#include <iostream>
#include <stack>
using namespace std;

class Solution
{
public:
    static bool isValid(string s)
    {
        if (s.length() <= 1)
            return false;

        stack<char> p;
        for (int i = 0; i < s.length(); i++)
        {
            if (p.size() > 0 && ((s[i] == ')' && p.top() == '(') || (s[i] == ']' && p.top() == '[') || (s[i] == '}' && p.top() == '{')))
            {
                p.pop();
            }
            else
            {
                p.push(s[i]);
            }
        }

        return p.size() == 0;
    }
};

int main()
{
    string s = "()";
    cout << Solution::isValid(s) << endl;
    return 0;
}