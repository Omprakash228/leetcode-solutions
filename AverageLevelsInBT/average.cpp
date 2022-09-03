#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr){}
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode* l, TreeNode* r) : val(x), left(l), right(r){}
};

class Solution {
public:
    static vector<double> averageOfLevels(TreeNode* root) {
        vector<double> result;
        if(root == NULL) return result;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int size = q.size();
            int sum = 0;
            for(int i = 0; i < size; i++) {
                sum += q.front()->val;

                if(q.front()->left) q.push(q.front()->left);
                if(q.front()->right) q.push(q.front()->right);
                q.pop();
            }
            double avg = double(sum) / size;
            result.push_back(avg);
        }

        return result;
    }
};

int main() {
    TreeNode* one = new TreeNode(3);
    TreeNode* two = new TreeNode(9);
    TreeNode* three = new TreeNode(20);
    TreeNode* four = new TreeNode(15);
    TreeNode* five = new TreeNode(7);

    one->left = two;
    one->right = three;
    three->left = four;
    three->right = five;

    vector<double> result = Solution::averageOfLevels(one);

    for(double r : result) {
        cout << r << "\n";
    }

    return 0;
}