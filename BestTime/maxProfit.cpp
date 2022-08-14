#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    static int maxProfit(vector<int> &prices)
    {
        int currMin = prices[0];
        int profit = 0;

        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[i] < currMin)
            {
                currMin = prices[i];
            }
            int currProfit = prices[i] - currMin;
            if (currProfit > profit)
            {
                profit = currProfit;
            }
        }

        return profit;
    }
};

int main()
{
    vector<int> prices{2, 4, 1};

    cout << Solution::maxProfit(prices);

    return 0;
}