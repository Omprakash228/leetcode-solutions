#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    static int leastInterval(vector<char> &tasks, int n)
    {
        vector<int> freq(26, 0);

        for (char task : tasks)
        {
            freq[task - 'A']++;
        }
        sort(freq.begin(), freq.end());

        int max_value = freq[25] - 1;
        int intervals = max_value * n;

        for (int i = 24; i >= 0; i--)
        {
            intervals -= min(freq[i], max_value);
        }

        return intervals > 0 ? intervals + tasks.size() : tasks.size();
    }
};

int main()
{
    vector<char> tasks{'A', 'A', 'A', 'B', 'B', 'B'};
    cout << Solution::leastInterval(tasks, 2) << endl;
    return 0;
}