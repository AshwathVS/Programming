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
    
    TreeNode* flattenedRes(TreeNode* node) {
        if(node == NULL) return NULL;
        else {
            TreeNode* left = flattenedRes(node->left);
            TreeNode* right = flattenedRes(node->right);
            
            // both null
            if(left == NULL && right == NULL) return node;
            // left is null
            else if(left == NULL) {
                return right;
            }
            // right is null
            else if(right == NULL) {
                node->right = node->left;
                node->left = NULL;
                return left;
            } 
            // both is not null
            else {
                left->right = node->right;
                node->right = node->left;
                node->left = NULL;
                return right;
            }
        }
    }
    
    void flatten(TreeNode* root) {
        flattenedRes(root);
    }
};