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
    int maxDepth(TreeNode* root) {
        int acc = 0;
        int maxD = 0;
        return maxDepthHelper(root, acc, maxD);
    }

    int maxDepthHelper(TreeNode* root, int& depth, int& maxD) {
        if (!root) {
            return 0;
        }

        return 1 + max(maxDepthHelper(root->left, depth, maxD), maxDepthHelper(root->right, depth, maxD));     
    }
};
