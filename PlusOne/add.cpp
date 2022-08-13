#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    static vector<int> plusOne(vector<int> &digits)
    {
        int carry = 1;

        for (int i = digits.size() - 1; i >= 0; i--)
        {
            int sum = digits[i] + carry;
            digits[i] = sum % 10;
            carry = sum / 10;
        }

        if (carry != 0)
        {
            digits.insert(digits.begin(), carry);
        }

        return digits;
    }
};

int main()
{
    vector<int> digits{9, 9, 9};

    Solution::plusOne(digits);

    for (int i : digits)
    {
        cout << i << " ";
    }
}