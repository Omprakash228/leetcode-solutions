#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
    public:
        static bool isPossible(vector<int>& target) {
            int sum = accumulate(target.begin(), target.end(), 0);
            int size = target.size();

            while(size != sum) {
                vector<int>::iterator max = max_element(target.begin(), target.end());
                int maxIndex = max - target.begin();
                int diff = sum - *max;
                int replacement = *max - diff;

                cout << sum << " " << *max << " " << max - target.begin() << " " << replacement << endl;

                if(replacement < 1)
                    return false;
                
                sum = diff + replacement;
                target[maxIndex] = replacement;
            }
            return true;
        }
};

int main() {
    vector<int> target {9, 3, 5};
    cout << Solution::isPossible(target);
    return 0;
}