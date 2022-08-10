#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    static bool isMatch(string s, string p)
    {
        if (p.empty())
            return s.empty();

        bool firstMatch = (!s.empty() && (p[0] == s[0] || p[0] == '.'));

        if (p.length() >= 2 && p[1] == '*')
        {
            return (isMatch(s, p.substr(2)) || (firstMatch && isMatch(s.substr(1), p)));
        }
        else
        {
            return firstMatch && isMatch(s.substr(1), p.substr(1));
        }
    }

    static bool isMatchDp(string s, string p)
    {
        vector<vector<bool>> dp(s.length() + 1, vector<bool>(p.length() + 1, 0));
        dp[s.length()][p.length()] = true;

        for (int i = s.length(); i >= 0; i--)
        {
            for (int j = p.length() - 1; j >= 0; j--)
            {
                bool firstMatch = (i < s.length() && (p[j] == s[i] || p[j] == '.'));

                if (j + 1 < p.length() && p[j + 1] == '*')
                {
                    dp[i][j] = dp[i][j + 2] || firstMatch && dp[i + 1][j];
                }
                else
                {
                    dp[i][j] = firstMatch && dp[i + 1][j + 1];
                }
            }
        }

        return dp[0][0];
    }
};

int main()
{
    cout << Solution::isMatch("aa", "b*") << "\n";
    return 0;
}