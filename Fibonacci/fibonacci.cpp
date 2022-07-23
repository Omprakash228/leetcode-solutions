#include <iostream>

using namespace std;

class Solution {
    public: 
        static int fib(int n) {
            if(n == 0 || n == 1) return n;

            return fib(n - 1) + fib(n - 2);
        }
};

int main() {
    cout << Solution::fib(8) << endl;
    return 0;
}