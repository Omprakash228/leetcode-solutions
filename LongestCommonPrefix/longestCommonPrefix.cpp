#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public: 
        static string longestCommonPrefix(vector<string>& strs) {
            string result = "";
            for(int i = 0; i < strs[0].length(); i++) {
                for(int j = 1; j < strs.size(); j++) {
                    if(strs[j][i] == '\0' || strs[j][i] != strs[0][i]) {
                        return result;
                    }
                }
                result += strs[0][i];
            }

            return result;
        }
};

int main() {
    vector<string> strs{"dog", "car"};
    cout << Solution::longestCommonPrefix(strs) << endl;
    return 0;
}