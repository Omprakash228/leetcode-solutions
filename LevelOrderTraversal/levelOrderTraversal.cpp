#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    static vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> result;
        queue<TreeNode *> elements;

        if (root == NULL)
            return result;

        elements.push(root);

        while (!elements.empty())
        {
            vector<int> level;
            int size = elements.size();

            for (int i = 0; i < size; i++)
            {
                TreeNode *node = elements.front();
                if (node->left)
                    elements.push(node->left);
                if (node->right)
                    elements.push(node->right);
                elements.pop();
                level.push_back(node->val);
            }
            result.push_back(level);
        }
        return result;
    }
};

int main()
{
    TreeNode *root = new TreeNode(3);
    TreeNode *fl = new TreeNode(9);
    TreeNode *fr = new TreeNode(20);
    TreeNode *srl = new TreeNode(15);
    TreeNode *srr = new TreeNode(7);
    root->left = fl;
    root->right = fr;
    fr->left = srl;
    fr->right = srr;

    vector<vector<int>> levels = Solution::levelOrder(root);

    for (vector<int> level : levels)
    {
        for (int e : level)
        {
            cout << e << " ";
        }
        cout << endl;
    }

    return 0;
}