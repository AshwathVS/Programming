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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val > q->val) {
            TreeNode* tmp = p;
            p = q;
            q = tmp;
        }
        return lowestCA(root, p, q);
    }
    
    TreeNode* lowestCA(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val < root->val && q->val > root->val) return root;
        else if(root->val == q->val || root->val == p->val) return root;
        else if(q->val < root->val && p->val < root->val) return lowestCA(root->left, p, q);
        else return lowestCA(root->right, p, q);
    }
};