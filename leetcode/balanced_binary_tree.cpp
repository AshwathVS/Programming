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
    bool isBalanced(TreeNode* root) {
        int height = 0;
        return isBalanced(root, &height);
    }
    
    bool isBalanced(TreeNode* node, int* height) {
        int left = 0, right = 0;
        
        if (node == NULL) {
            *height = 0;
            return true;
        } else {
            bool lt = isBalanced(node->left, &left);
            bool rt = isBalanced(node->right, &right);
            *height = max(left, right) + 1;
            
            if (abs(left - right) >= 2) {
                return false;
            } else {
                return lt && rt;
            }
        }
    }
};