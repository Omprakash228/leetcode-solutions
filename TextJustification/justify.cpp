#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static vector<string> justify(vector<string>& words, int maxWidth) {

    }
};

int main() {
    vector<string> words{"This", "is", "an", "example"};
    vector<string> result = Solution::justify(words, 20);

    for(string s : result) {
        cout << s << "\n";
    }
    return 0;
}