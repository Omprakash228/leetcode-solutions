#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    static void solve(int open, int close,vector<string> &ans,string temp){
        if(open == 0 && close == 0){
            ans.push_back(temp);
            return;
        }
        if(open > 0){
            solve(open-1,close,ans,temp+'(');
        }
        if(close > 0 && open < close){
            solve(open,close-1,ans,temp+')');
        }
    }
    
    static vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve(n,n,ans,"");
        return ans;
    }
};

int main()
{
    vector<string> result = Solution::generateParenthesis(1);

    for (string pattern : result)
    {
        cout << pattern << endl;
    }
    return 0;
}