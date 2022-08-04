#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    public:
        static vector<vector<int>> zigzag(TreeNode *root) {
            vector<vector<int>> result{};
            stack<TreeNode*> s1{};
            stack<TreeNode*> s2{};
            
            if(root != NULL)
                s1.push(root);
            
            while(!s1.empty() || !s2.empty()) {
                vector<int> level{};
                while(!s1.empty()) {
                    TreeNode* top = s1.top();
                    level.push_back(top->val);
                    if(top->left != NULL)
                        s2.push(top->left);
                    if(top->right != NULL)
                        s2.push(top->right);
                    
                    s1.pop();
                    
                }
                if(level.size() != 0)
                    result.push_back(level);
                level.clear();
                
                while(!s2.empty()) {
                    TreeNode* top = s2.top();
                    level.push_back(top->val);
                    if(top->right != NULL)
                        s1.push(top->right);
                    if(top->left != NULL)
                        s1.push(top->left);
                    
                    s2.pop();
                }
                if(level.size() != 0)
                    result.push_back(level);
            }
            
            return result;
        }
};

int main() {
    TreeNode *one = new TreeNode(3);
    TreeNode *two = new TreeNode(9);
    TreeNode *three = new TreeNode(20);
    TreeNode *four = new TreeNode(11);
    TreeNode *five = new TreeNode(13);
    TreeNode *six = new TreeNode(15);
    TreeNode *seven = new TreeNode(7);


    one->left = two;
    one->right = three;

    two->left = four;
    four->right = five;
    four->left = new TreeNode(5);

    three->left = six;
    three->right = seven;

    TreeNode *root = one;

    vector<vector<int>> result = Solution::zigzag(root);

    for(vector<int> i: result) {
        for(int e: i) {
            cout << e << " ";
        }
        cout << endl;
    }


    return 0;
}