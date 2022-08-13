#include <iostream>
#include <vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr){};
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){};
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){};
};

class Solution
{
public:
    static bool isValid(TreeNode *root)
    {
        // bool result = helper(root, LONG_MIN, LONG_MAX);
        vector<int> elements{};
        inOrder(root, elements);

        for (int i = 1; i < elements.size(); i++)
        {
            if (elements[i] <= elements[i - 1])
                return false;
        }

        return true;
    }

    static void inOrder(TreeNode *root, vector<int> &elements)
    {
        if (root == NULL)
            return;

        inOrder(root->left, elements);
        elements.push_back(root->val);
        inOrder(root->right, elements);
    }

    static bool helper(TreeNode* root, long low, long high) {
        if(root == NULL)
            return true;

        if(root->val > low && root-> val < high) {
            return (helper(root->left, low, root->val) && helper(root->right, root->val, high));
        }
        else {
            return false;
        }
    }
};

int main()
{
    TreeNode *root = new TreeNode(5);
    TreeNode *l1 = new TreeNode(3);
    TreeNode *r1 = new TreeNode(7);
    TreeNode *l2 = new TreeNode(1);
    TreeNode *l3 = new TreeNode(4);
    TreeNode *r2 = new TreeNode(5);
    TreeNode *r3 = new TreeNode(8);

    root->left = l1;
    root->right = r1;

    l1->left = l2;
    l1->right = l3;

    r1->left = r2;
    r1->right = r3;

    cout << Solution::isValid(root) << endl;
    return 0;
}