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
    int mSum;

    int maxPathSum(TreeNode* root) {
        /*
            Solution:
            
            Maximum path including current node = 
            max(curr, curr+left, curr+right, curr+left+right)

            Perform BFS on tree and pass maximums up in post-order fashion to build bottom up
        */
        mSum = root->val;
        
        dfs(root);

        return mSum;
    }

    int dfs(TreeNode* root) {
        if (!root)
            return 0;

        int val = root->val;
        
        int lSum = dfs(root->left);

        int rSum = dfs(root->right);

        int sum = max(val, max(val+lSum, max(val+rSum, val+lSum+rSum)));
        
        if (sum > mSum)
            mSum = sum;
        
        return max(val, max(val+lSum, val+rSum));
    }
};
