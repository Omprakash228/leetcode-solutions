#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    public:
        static int maxUnits(vector<vector<int>>& boxTypes, int truckSize) {
            sort(boxTypes.begin(), boxTypes.end(), largerUnit);
            int units = 0;

            for(int i = 0; i < boxTypes.size() && truckSize > 0; i++) {
                vector<int> b = boxTypes[i];
                if(b[0] >= truckSize) {
                    units += truckSize*b[1];
                    truckSize = 0;
                } else {
                    units += b[0]*b[1];
                    truckSize -= b[0];
                }
            }
            return units;
        }

        static bool largerUnit(vector<int>& v1, vector<int>& v2) {
            return v1[1] > v2[1];
        }
};

int main() {
    vector<vector<int>> boxTypes{{5, 10}, {2, 5}, {4, 7}, {3, 9}};
    cout << Solution::maxUnits(boxTypes, 10) << endl;
    return 0;
}