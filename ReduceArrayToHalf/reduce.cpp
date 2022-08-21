#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    static int minSize(vector<int>& arr) {
        unordered_map<int, int> freqMap;
        vector<int> freq;

        for(int i : arr) {
            freqMap[i]++;
        }

        for(unordered_map<int, int>::iterator it = freqMap.begin(); it != freqMap.end(); it++) {
            freq.push_back(it->second);
        }

        sort(freq.begin(), freq.end(), greater<int>());
        int remove = 0;

        for(int i = 0; i < freq.size(); i++) {
            remove += freq[i];
            if(arr.size() - remove <= arr.size()/2) {
                return i+1;
            }
        }

        return 0;
    }
};

int main() {
    vector<int> arr{7, 7, 7, 7, 7, 7};

    cout << Solution::minSize(arr);

    return 0;
}