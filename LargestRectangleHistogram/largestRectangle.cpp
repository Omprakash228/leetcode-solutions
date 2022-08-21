#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
    static int area(vector<int>& heights)
    {
        stack<int> s;
        s.push(-1);
        int maxArea = 0;

        for(int i = 0; i < heights.size(); i++) {
            maxArea = max(maxArea, heights[i]);

            while(s.size() > 1 && heights[i] < heights[s.top()]) {
                int h = heights[s.top()];
                s.pop();
                int w = i - s.top() - 1;
                maxArea = max(maxArea, h * w);
            }

            s.push(i);
        }

        while(s.size() > 1) {
            int h = heights[s.top()];
            s.pop();
            int w = heights.size() - s.top() - 1;
            maxArea = max(maxArea, h*w);
        }

        return maxArea;
    }
};

int main()
{
    vector<int> heights{1, 2, 2};
    cout << Solution::area(heights);
    return 0;
}