#include <iostream>
#include <numeric>

using namespace std;

class Solution {
    public:
        static int minPartitions(string n) {
            int p = 0;

            for(int i = 0; i < n.length(); i++) {
                p = max(p, n[i] - '0');
            }
            return p;
        }
};

int main(int argc, char **argv) {
    string n = "27346209830709182346";
    cout << Solution::minPartitions(n) << endl;
    return 0;
}