#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int count = 0;
    vector<int> movesToStamp(string stamp, string target) {
        vector<int> result{};
        vector<bool> visited(target.size(), false);
        int s = stamp.size();
        int t = target.size();
        
        while(count != t) {
            bool didChange = false;
            for(int i = 0; i <= t-s; i++) {
                if(!visited[i] && canReplace(target, i, stamp)){
                    replace(target, i, s);
                    visited[i] = true;
                    result.push_back(i);
                    didChange = true;

                    if(count == t){
                        break;
                    }
                }
            }

            if(!didChange)
            {
                return vector<int>();
            }

        }

        reverse(result.begin(), result.end());
        return result;
    }

    bool canReplace(string target, int pos, string stamp) {
        for(int i = 0; i < stamp.size(); i++) {
            if(target[i+pos] != '?' && target[i+pos] != stamp[i]) {
                return false;
            }
        }
        return true;
    }

    void replace(string &target, int pos, int len) {
        for(int i = 0; i < len; i++) {
            if(target[i+pos] != '?') {
                target[i+pos] = '?';
                count++;
            }
        }
    }
};


int main() {
    string stamp = "abca";
    string target = "accaa";

    Solution s;
    vector<int> result = s.movesToStamp(stamp, target);

    for(int r : result) {
        cout << r << " ";
    }

    return 0;
}