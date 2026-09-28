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
    vector<int> sol;
    vector<int> preorderTraversal(TreeNode* root) {
        dfs(root);
        return sol;
    }

    void dfs(TreeNode* r) {
        if (r == nullptr)
            return;
        
        sol.push_back(r->val);

        if (r->left)
            dfs(r->left);

        if (r->right)
            dfs(r->right);
    }
};