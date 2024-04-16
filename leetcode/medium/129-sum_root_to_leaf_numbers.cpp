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
    int sumNumbers(TreeNode* root) {
        if (root->left == nullptr && root->right == nullptr) return root->val;
        return helper(root->left, to_string(root->val)) + helper(root->right, to_string(root->val));
    }

    int helper(TreeNode* root, string current) {
        if (root == nullptr) return 0;
        string n = current + to_string(root->val);
        if (root->left == nullptr && root->right == nullptr) return stoi(n);
        return helper(root->left, n) + helper(root->right, n);
    }
};
