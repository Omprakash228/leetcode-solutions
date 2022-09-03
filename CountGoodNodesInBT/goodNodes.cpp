#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode* l, TreeNode* r) : val(x), left(l), right(r){}
};

class Solution {
    int count = 0;
public:
    int goodNodes(TreeNode* root) {
        callDFS(root, INT_MIN);

        return count;
    }

    void callDFS(TreeNode* node, int max) {
        if(node == NULL) return;

        if(node->val >= max) {
            count++;
            max = node->val;
        }
        callDFS(node->left, max);
        callDFS(node->right, max);
    }
};

int main() {
    TreeNode* one = new TreeNode(3);
    TreeNode* two = new TreeNode(3);
    TreeNode* three = new TreeNode(4);
    TreeNode* four = new TreeNode(2);
    // TreeNode* five = new TreeNode(1);
    // TreeNode* six = new TreeNode(5);

    // one->left = two;
    // two->left = three;
    // two->right = four;

    Solution s;
    cout << s.goodNodes(nullptr);
    return 0;
}