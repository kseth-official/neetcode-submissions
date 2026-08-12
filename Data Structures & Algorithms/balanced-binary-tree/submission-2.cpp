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
    bool solution = true;

    bool isBalanced(TreeNode* root) {
        isBalancedHelper(root);

        return solution;
    }

    int isBalancedHelper(TreeNode* root) {
        if (!root) return 0;

        // preorder traversal
        int leftDepth = isBalancedHelper(root->left);
        // inorder traversal
        int rightDepth = isBalancedHelper(root->right);
        // postorder traversal

        if (abs(leftDepth - rightDepth) > 1) {
            // not balanced
            solution = false;
        }

        return 1 + max(leftDepth,rightDepth);
    }
};
