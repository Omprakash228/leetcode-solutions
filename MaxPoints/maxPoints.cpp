#include<iostream>
#include<vector>
#include<numeric>
#include<bits/stdc++.h>

using namespace std;

class Solution {
    public:
        static int maxPoints(vector<int>& cards, int k) {
            int n = cards.size();
            int minL = n-k;
            int sum = accumulate(cards.begin(), cards.end(), 0);

            if(n == k)
                return sum;

            int minPoints = INT_MAX;
            vector<int> minSum(k+1, 0);

            for(int i = 0; i < minL; i++) {
                minSum[0] += cards[i];
            }
            minPoints = min(minPoints, minSum[0]);

            for(int i = 1; i <= k; i++) {
                int s = minSum[i-1] - cards[i-1] + cards[i+minL-1];
                minSum[i] = s;
                minPoints = min(minPoints, minSum[i]);
            }

            return sum-minPoints;
        }
};

int main() {
    vector<int> cards{5, 2, 2, 4, 1};
    cout << Solution::maxPoints(cards, 2) << endl;
    return 0;
}