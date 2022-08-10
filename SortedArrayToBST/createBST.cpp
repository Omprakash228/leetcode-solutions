#include <iostream>
#include <vector>
#include <queue>

using namespace std;


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr){};
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){};
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(nullptr), right(nullptr){}
};

class Solution {
public:
    static TreeNode* sortedArrayToBST(vector<int>& nums) {
        return solve(nums, 0, nums.size() - 1);
    }

    static TreeNode* solve(vector<int>& nums, int left, int right) {
        if(left > right) return NULL;

        int mid = ((right - left + 1) / 2) + left;
        int mE = nums[mid];
        TreeNode* root = new TreeNode(mE);
        root->left = solve(nums, left, mid - 1);
        root->right = solve(nums, mid + 1, right);
        return root;
    }
};

int main() {
    vector<int> nums{-10, -3, 0, 5, 9};

    TreeNode* resultRoot = Solution::sortedArrayToBST(nums);

    queue<TreeNode*> q;
    q.push(resultRoot);

    while(!q.empty()) {
        TreeNode* front = q.front();

        cout << front->val << endl;

        if(front->left != nullptr) {
            q.push(front->left);
        }
        if(front->right != nullptr) {
            q.push(front->right);
        }

        q.pop();
    }
    return 0;
}