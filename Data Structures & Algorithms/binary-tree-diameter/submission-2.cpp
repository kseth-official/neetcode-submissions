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
    int maxDiameter = 0;

    int diameterOfBinaryTree(TreeNode* root) {
        maxHeightHelper(root);
        return maxDiameter;
    }

    int maxHeightHelper(TreeNode* root) {
        if (!root)
            return 0;

        //preorder
        int leftHeight = maxHeightHelper(root->left);
        //inorder
        int rightHeight = maxHeightHelper(root->right);
        //postorder

        maxDiameter = max(leftHeight + rightHeight, maxDiameter);

        return 1 + max(leftHeight, rightHeight);
    }

};
