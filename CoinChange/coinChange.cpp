#include<iostream>
#include<vector>
#include<bits/stdc++.h>

using namespace std;

class Solution {
    public:
        static int coinChange(vector<int>& coins, int amount) {
            vector<int> dp(amount+1, INT_MAX);
            dp[0] = 0;

            for(int i = 1; i <= amount; i++) {
                for(int j : coins) {
                    if(j <= i) {
                        int rem = dp[i-j];

                        if(rem != INT_MAX && rem+1 < dp[i])
                            dp[i] = rem + 1;
                    }
                }
            }

            return dp[amount] != INT_MAX ? dp[amount] : -1;
        }
};

int main() {
    vector<int> coins{2};
    cout << Solution::coinChange(coins, 0);
    return 0;
}