#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    static vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int i = 0, j = 0;
        while(i < nums1.size() && j < nums2.size()) {
            if(nums1[i] == nums2[j]) {
                result.push_back(nums1[i++]);
                j++;
            }
            else if(nums1[i] < nums2[j]) {
                i++;
            }
            else {
                j++;
            }
        }

        return result;
    }

    static vector<int> intersection2(vector<int> nums1, vector<int> nums2) {
        unordered_map<int, int> elements;
        vector<int> result;

        for(int i : nums1) {
            elements[i]++;
        }

        for(int j : nums2) {
            if(elements[j] != 0) {
                result.push_back(j);
                elements[j]--;
            }
        }

        return result;
    }
};

int main() {
    vector<int> nums1{4, 9, 5};
    vector<int> nums2{9, 4, 9, 8, 4};

    vector<int> result = Solution::intersection2(nums1, nums2);

    for(int i : result) {
        cout << i << " ";
    }
    return 0;
}