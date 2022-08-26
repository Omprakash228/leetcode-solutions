#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    static int minMeetingRooms(vector<vector<int>>& intervals) {
        int minRooms = 0;
        map<int, int> roomMap;

        for(vector<int> interval : intervals) {
            roomMap[interval[0]]++;
            roomMap[interval[1]]--;
        }

        int rooms = 0;
        for(map<int, int>::iterator it = roomMap.begin(); it != roomMap.end(); it++) {
            minRooms = max(minRooms, rooms += it->second);
        }

        return minRooms;
    }
};

int main() {
    vector<vector<int>> intervals{{0, 30}, {5, 10}, {15, 20}};
    vector<vector<int>> intervals1{{7, 10}, {2, 4}};

    cout << Solution::minMeetingRooms(intervals1);
    return 0;
}