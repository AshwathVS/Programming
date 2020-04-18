/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return recurse(root, root);
    }
    
    bool recurse(TreeNode* a, TreeNode* b) {
        if (a == NULL && b == NULL) {
            return true;
        } else if (a == NULL || b == NULL) {
            return false;
        } else {
            return a->val == b->val && recurse(a->left, b->right) && recurse(a->right, b->left);
        }
    }
};