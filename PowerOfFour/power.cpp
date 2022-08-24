#include <iostream>
#include <math.h>
using namespace std;

class Solution {
public:
    static bool isPowerOfFour(int n) {
        if(n == 1) 
            return true;        
        if(n < 4) 
            return false;
        
        int rem = n % 4;
        if(rem != 0)
            return false;
        else 
            return isPowerOfFour(n/4);

        // double i = log(n) / log(4);
        // return n > 0 && i == trunc(i);
    }
};

int main() {
    cout << Solution::isPowerOfFour(1) << endl;
    return 0;
}