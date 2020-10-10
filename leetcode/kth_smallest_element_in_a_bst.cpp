class Solution {
    void inorder(TreeNode* node, int &ans, int& k) {
        if(node == NULL) return;
        else {
            inorder(node->left, ans, k);
            --k;
            if(k == 0) {
                ans = node->val;
                return;
            }
            inorder(node->right, ans, k);
        }
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        int ans = 0;
        inorder(root, ans, k);
        return ans;
    }
};