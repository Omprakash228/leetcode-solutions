#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution
{
public:
    int result = INT_MIN;
    int getKadaneSum(vector<int>& nums) {
        int currSum = 0;
        int maxSum = INT_MIN;
        for(int n : nums) {
            currSum = max(n, currSum + n);
            maxSum = max(maxSum, currSum);
        }
        return maxSum;
    }

    void updateResult(vector<int> &nums, int k)
    {
        int kadaneSum = getKadaneSum(nums);
        if(kadaneSum <= k)
        {
            result = max(result, kadaneSum);
            return;
        }

        int sum = 0;

        set<int> sortedSum;
        set<int>::iterator it;
        sortedSum.insert(0);

        for (int &n : nums)
        {
            sum += n;

            it = sortedSum.lower_bound(sum - k);

            if (it != sortedSum.end())
            {
                result = max(result, sum - *it);
            }

            sortedSum.insert(sum);
        }
    }

    int maxSubMatrix(vector<vector<int>> &matrix, int k)
    {
        if (matrix[0].size() > matrix.size())
        {
            vector<int> rowSum(matrix[0].size());
            for (int i = 0; i < matrix.size(); i++)
            {
                fill(rowSum.begin(), rowSum.end(), 0);

                for (int r = i; r < matrix.size(); r++)
                {
                    for (int c = 0; c < matrix[0].size(); c++)
                    {
                        rowSum[c] += matrix[r][c];
                    }
                    updateResult(rowSum, k);

                    if (result == k)
                        return result;
                }
            }
        } else {
            vector<int> colSum(matrix.size());
            for(int i = 0; i < matrix[0].size(); i++) {

                fill(colSum.begin(), colSum.end(), 0);
                for(int c = i; c < matrix[0].size(); c++) {
                    for(int r = 0; r < matrix.size(); r++) {
                        colSum[r] += matrix[r][c];
                    }

                    updateResult(colSum, k);

                    if(result == k)
                        return result;
                }
            }
        }
        vector<int> rowSum(matrix[0].size());
        for(int i = 0; i < matrix.size(); i++) {
            fill(rowSum.begin(), rowSum.end(), 0);

            for(int r = i; r < matrix.size(); r++) {
                for(int c = 0; c < matrix[0].size(); c++) {
                    rowSum[c] += matrix[r][c];
                }
                updateResult(rowSum, k);

                if(result == k)
                    return result;
            }
        }

        return result;
    }
};

int main()
{
    vector<vector<int>> matrix{{1, 0, 1}, {0, -2, 3}};

    Solution obj;
    cout << obj.maxSubMatrix(matrix, 2);

    return 0;
}