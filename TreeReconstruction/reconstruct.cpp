#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>

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
    static int preorderIndex;

public:
    static TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        preorderIndex = 0;
        unordered_map<int, int> inorderMap;
        for (int i = 0; i < inorder.size(); i++)
        {
            inorderMap.insert({inorder[i], i});
        }
        return arrayToTree(preorder, 0, preorder.size() - 1, inorderMap);
    }

    static TreeNode *arrayToTree(vector<int> &preorder, int left, int right, unordered_map<int, int> &inorderMap)
    {
        if (left > right)
            return NULL;

        int rootValue = preorder[preorderIndex++];
        TreeNode *root = new TreeNode(rootValue);

        unordered_map<int, int>::iterator it = inorderMap.find(rootValue);
        int newRight = it->second - 1;
        int newLeft = it->second + 1;
        root->left = arrayToTree(preorder, left, newRight, inorderMap);
        root->right = arrayToTree(preorder, newLeft, right, inorderMap);
        return root;
    }
};

int Solution::preorderIndex = 0;

int main()
{
    vector<int> preorder{3, 9, 20, 15, 7};
    vector<int> inorder{9, 3, 15, 20, 7};

    TreeNode *root = Solution::buildTree(preorder, inorder);

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        int size = q.size();

        for (int i = 0; i < size; i++)
        {
            TreeNode *node = q.front();

            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);

            cout << node->val << " ";

            q.pop();
        }
        cout << endl;
    }

    return 0;
}