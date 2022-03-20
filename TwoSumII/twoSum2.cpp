#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public: 
        static vector<int> twoSum(vector<int>& numbers, int target) {
            vector<int> result;

            int a_pointer = 0;
            int b_pointer = numbers.size() - 1;

            while (a_pointer < b_pointer) {
                int sum = numbers[a_pointer] + numbers[b_pointer];

                if (sum > target) {
                    b_pointer--;
                } else if (sum < target) {
                    a_pointer++;
                } else {
                    result.push_back(a_pointer);
                    result.push_back(b_pointer);
                    return result;
                }
            }
            return result;
        }
};

int main() {
    vector<int> numbers{-1, 0};
    vector<int> result = Solution::twoSum(numbers, -1);

    cout << result[0] << "\t" << result[1];

    return 0;
}

