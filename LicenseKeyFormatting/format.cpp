#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
    static string format(string s, int k)
    {
        string res;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] != '-')
            {
                res += toupper(s[i]);
            }
        }

        s = res;
        res = "";
        for(int i = s.length() - 1; i >= 0; i--) {
            res += s[i];
            if((s.length() - i) % k == 0 && i != 0) {
                res += "-" ;
            }
        }
        reverse(res.begin(), res.end());

        return res;
    }
};

int main()
{
    string s = "2-5g-3-J";
    int k = 4;
    cout << Solution::format(s, k) << endl;
    return 0;
}