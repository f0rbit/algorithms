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
    string smallestFromLeaf(TreeNode* root) {
        return helper(root, "");
    }

    string helper(TreeNode* current, string str) {
        if (current == nullptr) {
            return str;
        }
        string new_val = char(current->val + 'a') + str;
        if (current->left == nullptr && current->right == nullptr) {
            return new_val;
        }
        if (current->left == nullptr) {
            return helper(current->right, new_val);
        }
        if (current->right == nullptr) {
            return helper(current->left, new_val);
        }
        string left = helper(current->left, new_val);
        string right = helper(current->right, new_val);
        return left > right ? right : left;
    }
};
