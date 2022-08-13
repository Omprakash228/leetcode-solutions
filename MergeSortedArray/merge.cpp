#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        m--; n--;
        int k = nums1.size() - 1;

        while(m >= 0 && n >= 0) {
            nums1[k--] = nums1[m] > nums2[n] ? nums1[m--] : nums2[n--];
        }
        while(n >= 0) {
            nums1[k--] = nums2[n--];
        }
    }
};

int main() {
    vector<int> nums1{1, 3, 6, 0, 0, 0};
    vector<int> nums2{2, 4, 5};
    int m = 3;
    int n = 3;

    Solution::merge(nums1, m, nums2, n);

    for(int i : nums1) {
        cout << i << " ";
    }

    return 0;
}