/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root)
            return false;

        stack<pair<TreeNode*, int>> s;

        s.push({root, root->val});

        while (!s.empty()) {
            auto [n, sum] = s.top();
            s.pop();

            if (n->left)
                s.push({n->left, sum + n->left->val}); 
            if (n->right)
                s.push({n->right, sum + n->right->val}); 
            
            if (n->left == nullptr && n->right == nullptr && targetSum == sum)
                return true;
        }

        return false;
    }
};