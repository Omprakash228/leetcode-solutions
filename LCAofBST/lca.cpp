#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {};
};

class Solution {
public:
    static TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(p->val < root->val && q->val < root->val) 
            return lca(root->left, p, q);
        
        if(p->val > root->val && q->val > root->val)
            return lca(root->right, p, q);
        
        return root;       
    }
};

int main() {
    TreeNode* root = new TreeNode(6);
    TreeNode* l1 = new TreeNode(2);
    TreeNode* r1 = new TreeNode(8);

    TreeNode* l2 = new TreeNode(0);
    TreeNode* l3 = new TreeNode(3);
    l1->left = l2;
    l1->right = l3;

    TreeNode* l4 = new TreeNode(1);
    TreeNode* l5 = new TreeNode(4);
    l3->left = l4;
    l3->right = l5;

    root->left = l1;
    root->right = r1;

    TreeNode* result = Solution::lca(root, l1, l5);

    cout << result->val;

    return 0;
}