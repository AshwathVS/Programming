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
    int maxDepth(TreeNode* root) {
        return recurse(root, 0);
    }
    
    int recurse(TreeNode* node, int depth) {
        if (node == NULL) {
            return depth;
        } else {
            return max(recurse(node->left, depth + 1), recurse(node->right, depth + 1));
        }
    }
    
    int max(int a, int b) {
        if (a > b) {
            return a;
        } else {
            return b;
        }
    }
};