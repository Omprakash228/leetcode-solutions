#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static int maxProfit(vector<int>& prices) {
        int pick = INT_MAX;
        int profit = 0;

        for(int i = 0; i < prices.size(); i++) {
            if(prices{i] < pick) {
                pick = prices{i];
            }

            if(prices{i] > pick) {
                profit += prices{i] - pick;
                pick = prices{i];
            }
        }

        return profit;
    }
};

int main() {
    vector<int> prices{7, 1, 5, 3, 6, 4};

    cout << Solution::maxProfit(prices) << endl;

    return 0;
}