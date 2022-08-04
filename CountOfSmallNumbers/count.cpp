#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
    public:
    static vector<int> countSmaller(vector<int>& nums) {
        vector<int> copy = nums;
        unordered_map<int, priority_queue<int>> indexMap{};

        sort(copy.begin(), copy.end());

        for(int i=0; i < copy.size(); i++) {
            if(i == 0) {
                indexMap.insert({i, })
            }
        }

    }
};

int main() {
    vector<int> nums{5, 2, 6, 1};
    vector<int> result = Solution::countSmaller(nums);

    for(int i : result) {
        cout << i << " ";
    }

    return 0;
}