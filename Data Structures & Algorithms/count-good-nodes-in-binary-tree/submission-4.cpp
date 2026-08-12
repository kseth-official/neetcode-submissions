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

    int count = 0;
    vector<int> good;
    
    int goodNodes(TreeNode* root) {
        helper(root, root->val);
        return count;
    }

    void helper(TreeNode* root, int maxTN) {
        if (!root) return;
        if (root->val >= maxTN) {
            count++;
            good.push_back(root->val);
        }
        helper(root->left, max(root->val,maxTN));
        helper(root->right, max(root->val,maxTN));
    }
};
