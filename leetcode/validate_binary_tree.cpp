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
    void inorder(TreeNode* node, vector<int>& res) {
        if(node == NULL) return;
        else {
            inorder(node->left, res);
            res.push_back(node->val);
            inorder(node->right, res);
        }
    }
    
    bool isValidBST(TreeNode* root) {
        vector<int> in;
        inorder(root, in);
        
        for(int i=1; i<in.size(); i++) {
            if(in[i] <= in[i-1]) return false;
        }
        
        return true;
    }
};