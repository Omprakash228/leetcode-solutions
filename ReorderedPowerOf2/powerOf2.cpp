#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static bool reorderedPowerOf2(int n) {
        vector<int> countN = count(n);
        for(int i = 0; i < 31; i++) {
            if(countN == count(1 << i)) {
                return true;
            }
        }
        return false;
    }

    static vector<int> count(int n) {
        vector<int> result(10, 0);
        while(n > 0) {
            result[n%10]++;
            n /= 10;
        }
        return result;
    }
};

int main() {
    cout << Solution::reorderedPowerOf2(46);
    return true;
}