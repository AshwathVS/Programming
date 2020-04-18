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
    bool hasPathSum(TreeNode* root, int sum) {
        return hasPathSum(root, sum, 0);
    }
    
    bool hasPathSum(TreeNode* node, int sum, int runningSum) {
        if (node == NULL) {
            return false;
        } else if (runningSum + node->val == sum) {
            if (node->right == NULL && node->left == NULL) return true;
        } 
            return hasPathSum(node->left, sum, runningSum + node->val) || hasPathSum(node->right, sum, runningSum + node->val);
        
    }
};