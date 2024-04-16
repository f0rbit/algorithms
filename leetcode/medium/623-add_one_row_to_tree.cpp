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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 0) return root;
        if (depth == 1) {
            TreeNode* above = new TreeNode(val);
            above->left = root;
            return above;
        }
        helper(root, val, depth - 1);
        return root;
    }

    void helper(TreeNode* current, int val, int depth) {
        if (current == nullptr) return;
        if (depth == 0) return;
        if (depth == 1) {
            TreeNode* new_left = new TreeNode(val);
            TreeNode* new_right = new TreeNode(val);
            if (current->left != nullptr) {
                new_left->left = current->left;
            }
            if (current->right != nullptr) {
                new_right->right = current->right;
            }
            current->left = new_left;
            current->right = new_right;
        } else if (depth > 1) {
            helper(current->left, val, depth - 1);
            helper(current->right, val, depth - 1);
        }
        return;
    }
};
