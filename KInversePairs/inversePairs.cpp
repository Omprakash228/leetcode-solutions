#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution
{
    int s = 1001;
    vector<vector<int>> memo = vector<vector<int>>(s, vector<int>(s, -1));

public:
    int kInversePairs(int n, int k)
    {

        if (n == 0)
            return 0;
        if (k == 0)
            return 1;

        if (memo[n][k] > -1)
            return memo[n][k];

        int inv = 0;
        for (int i = 0; i <= min(k, n - 1); i++)
        {
            inv = (inv + kInversePairs(n - 1, k - i)) % 1000000007;
        }
        memo[n][k] = inv;
        return inv;
    }
};

int main()
{
    Solution *s = new Solution();
    cout << s->kInversePairs(3, 1);
    return 0;
}