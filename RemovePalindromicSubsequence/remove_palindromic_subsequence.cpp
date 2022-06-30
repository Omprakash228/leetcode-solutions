#include<iostream>

using namespace std;

class Solution {
    public:
        static int removePalindromSub(string s) {
            int limit = s.length() % 2 == 0 ? s.length() / 2 : (s.length() + 1) / 2;
            int i = 0, j = s.length() - 1;

            cout << limit << endl;


            for(;i < limit; i++, j--) {
                cout << i << " " << s[i] << " " << j << " " << s[j] << endl;
                if(s[i] != s[j])
                    break;
            }

            return i > j ? 1 : 2;
        }
};

int main() {
    int steps = Solution::removePalindromSub("ababab");
    cout << steps << endl;
    return 0;
}