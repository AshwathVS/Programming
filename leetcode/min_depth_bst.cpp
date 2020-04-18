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
    int minDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        } else {
            int lt = 0, rt = 0;
            if (root->left != NULL && root->right != NULL) {
                lt = minDepth(root->left);
                rt = minDepth(root->right);
                return min(lt, rt) + 1;
            } else if (root->left != NULL) {
                return minDepth(root->left) + 1;
            } else {
                return minDepth(root->right) + 1;
            }
        }
    }
};