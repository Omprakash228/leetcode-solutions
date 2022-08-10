#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution
{
    vector<vector<int>> mapping{{1, 2, 4},
                                {0, 2},
                                {1, 3},
                                {2},
                                {2, 3}};

public:
    int count(int n)
    {
        vector<vector<int>> dp(n, vector<int>(5, 0));
        dp[0] = vector<int>(5, 1);
        int sum = 5;

        for (int i = 1; i < n; i++)
        {
            sum = 0;
            for (int j = 0; j < mapping.size(); j++)
            {
                for (int m : mapping[j])
                {
                    dp[i][j] = (dp[i][j] + dp[i - 1][m]) % 1000000007;
                }

                if (i == n - 1)
                {
                    sum += (dp[i][j] % 1000000007);
                }
            }
        }

        return sum % 1000000007;
    }
};

int main()
{
    Solution s;
    cout << s.count(5) << endl;
    return 0;
}