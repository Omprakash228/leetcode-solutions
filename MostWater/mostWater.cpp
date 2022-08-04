#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
    public: 
        static int maxArea(vector<int>& height) {
            int area = 0;
            int n = height.size();
            int l = 0;
            int h = n - 1;

            while(l < h) {
                area = max(area, min(height[l], height[h]) * (h-l));
                if(height[l] < height[h])
                    l++;
                else 
                    h--;
            }
            return area;
        }
};

int main() {
    vector<int> height{1, 1};
    cout << Solution::maxArea(height) << endl;
    return 0;
}