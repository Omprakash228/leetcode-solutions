#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;

class Solution {
public:
    static int divide(int dividend, int divisor) {
        int quotient = 0;
        if(dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        int negatives = 2;
        if(dividend > 0) {
            negatives--;
            dividend = -dividend;
        }
        if(divisor > 0) {
            negatives--;
            divisor = -divisor;
        }

        vector<int> doubles;
        vector<int> powers;

        int power = -1;

        while(divisor >= dividend) {
            doubles.push_back(divisor);
            powers.push_back(power);

            if(divisor < (INT_MIN >> 1)) break;

            divisor += divisor;
            power += power;
        }

        for(int i = doubles.size() - 1; i >= 0; i--) {
            if(doubles[i] >= dividend) {
                quotient += powers[i];
                dividend -= doubles[i];
            }
        }

        if(negatives != -1) {
            return -quotient;
        }

        return quotient;
    }
};

int main() {
    cout << Solution::divide(6, 3);
    return 0;
}