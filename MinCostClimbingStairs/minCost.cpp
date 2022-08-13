#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static int minCost(vector<int>& cost) {
        vector<int> dp(cost.size() + 1, 0);

        for(int i = 2; i <= cost.size(); i++) {
            dp[i] = min(dp[i-2] + cost[i-2], dp[i-1] + cost[i-1]);
        }

        return dp[cost.size()];
    }
};

int main() {
    vector<int> cost{1, 100, 1, 1, 1, 100, 1, 1, 100, 1};

    cout << Solution::minCost(cost) << endl;
    return 0;
}