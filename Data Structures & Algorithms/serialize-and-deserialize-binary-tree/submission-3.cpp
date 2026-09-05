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

class Codec {
public:
    string s = "";

    /* TreeNode is
    {x {} {}} if it is a leaf node
    {x {y {...} {...}} {}} if it has a left child
    {x, {}, {y, {...}, {...}}} if it has a right child
    {x, {...}, {...}} if it has both children
    */

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        vector<string> tokens;

        encode(root, tokens);

        string result;
        for (int i=0;i<tokens.size();i++) {
            if (i > 0)
                result += ",";
            result+= tokens[i];
        }

        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> tokens;
        string token;

        stringstream ss(data);
        while (getline(ss, token, ',')) {
            tokens.push_back(token);
        }

        int index = 0;
        return decode(tokens, index);
    }


private:
    void encode(TreeNode* root, vector<string>& tokens) {
        if (root == nullptr) {
            tokens.push_back("N");
            return;
        }
        
        tokens.push_back(to_string(root->val));
        encode(root->left, tokens);
        encode(root->right, tokens);
    }


    TreeNode* decode(vector<string>& tokens, int& index) {
        if (tokens[index] == "N") {
            index++;
            return nullptr;
        }

        TreeNode* node = new TreeNode(stoi(tokens[index]));
        index++;

        node->left = decode(tokens, index);
        node->right = decode(tokens, index);

        return node;
    }
};