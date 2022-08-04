#include <iostream>

using namespace std;

class Solution {
    public:
        static int mirrorRelection(int p, int q) {
            while(p%2 == 0 && q%2 ==0) {
                p /= 2;
                q /= 2;
            }

            if(p%2 == 0 && q%2 != 0) 
                return 2;
            if(p%2 != 0 && q%2 != 0)
                return 1;
            
            return 0;
        }
};

int main() {
    cout << Solution::mirrorRelection(3, 1) << "\n";

    return 0;
}