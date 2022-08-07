#include <iostream>
#include <math.h>

using namespace std;

class Solution {
public:
    static int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        return ceil(log(buckets) / log((minutesToTest/minutesToDie) + 1));
    }
};

int main() {
    cout << Solution:: poorPigs(1000, 15, 60) << "\n";
    return 0;
}

//youtube.com/watch?v=lHU8Z-KS7U4