#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    public:
        static vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
            vector<vector<int>> queue;
            int n = people.size();

            sort(people.begin(), people.end(), compare);
            
            for(int i = 0; i < n; i++) {
                queue.insert(queue.begin() + people[i][1], people[i]);
            }

            return queue;
        }

        static bool compare(vector<int>& a, vector<int>& b) {
            if(a[0] == b[0])
                return a[1] < b[1];
            
            return a[0] > b[0];
        }

        static void printVector(vector<vector<int>>& v) {
            for(int i = 0; i < v.size(); i++) {
                cout << v[i][0] << ", " << v[i][1] << endl;
            }
        }
};

int main () {
    vector<vector<int>> people{{7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2}};
    vector<vector<int>> queue = Solution::reconstructQueue(people);
    Solution::printVector(queue);
    return 0;
}