#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr){}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode* l, TreeNode* r) : val(x), left(l), right(r){}
};

class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> leaves(TreeNode* root) {
        getHeight(root);
        return result;
    }

    int getHeight(TreeNode* node) {
        if(node == nullptr) {
            return -1;
        }

        int leftHeight = getHeight(node->left);
        int rightHeight = getHeight(node->right);

        int height = max(leftHeight, rightHeight) + 1;
        cout << node->val << ": " << height << endl;
        
        if(result.size() == height) result.push_back({});

        result[height].push_back(node->val);
        return height;
    }
};

int main() {
    TreeNode* one = new TreeNode(1);
    TreeNode* two = new TreeNode(2);
    TreeNode* three = new TreeNode(3);
    TreeNode* four = new TreeNode(4);
    TreeNode* five = new TreeNode(5);

    one->left = two;
    one->right = three;
    two->left = four;
    two->right = five;

    TreeNode* root = one;
    
    Solution s;
    vector<vector<int>> result = s.leaves(root);
    
    for(vector<int> r : result) {
        for(int e : r) {
            cout << e << " ";
        }
        cout << endl;
    }
    return 0;
}