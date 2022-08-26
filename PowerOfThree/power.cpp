#include <iostream>
#include <math.h>

using namespace std;

class Solution {
public:
    static bool isPowerOfThree(int n) {
        double i = log10(n) / log10(3);
        return n > 0 && i - int(i) == 0;
    }
};

int main() {
    cout << Solution::isPowerOfThree(243);
    return 0;
}