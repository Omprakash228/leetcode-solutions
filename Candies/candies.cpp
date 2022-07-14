#include<iostream>
#include<vector>
#include<numeric>

using namespace std;

class Solution {
    public:
        static int candy(vector<int>& ratings) {
            vector<int> candies(ratings.size(), 1);

            for(int i = 1; i < ratings.size(); i++) {
                if(ratings[i] > ratings[i-1]) {
                    candies[i] = candies[i-1] + 1;
                }
            }
            int sum = candies[ratings.size() - 1];
            for(int i = ratings.size() - 2; i >= 0; i--) {
                if(ratings[i] > ratings[i+1]) {
                    candies[i] = max(candies[i], candies[i+1] + 1);
                }
                sum += candies[i];
            }
            return sum;
        }
};

int main() {
    vector<int> ratings{1, 2, 2};
    cout << Solution::candy(ratings);
    return 0;
}

