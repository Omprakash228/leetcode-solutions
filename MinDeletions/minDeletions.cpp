#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
    public:
        static int minDeletions(string s) {
            vector<int> frequency(26, 0);
            for(char c : s) {
                frequency[c - 'a']++;
            }

            sort(frequency.begin(), frequency.end(), greater<int>());

            int maxFreq = s.length();
            int deleteCount = 0;

            for(int i = 0; i < 26 && frequency[i] > 0; i++) {
                if(frequency[i] > maxFreq) {
                    deleteCount += frequency[i] - maxFreq;
                    frequency[i] = maxFreq;
                }

                maxFreq = max(0, frequency[i] - 1);
            }
            return deleteCount;
        }
};

int main() {
    string s = "ceabaacb";
    cout << Solution::minDeletions(s) << endl;
    return 0;
}