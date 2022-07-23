#include <iostream>
#include <math.h>

using namespace std;

class Solution {
    public:
        static int steps(int n) {
            double sqrt5 = sqrt(5);
            double fibn = pow((1+sqrt5)/2, n+1) - pow((1-sqrt5)/2, n+1);
            return (int)(fibn/sqrt5);
        }
};

int main() {
    cout << Solution::steps(5) << "\n";
    return 0;
}