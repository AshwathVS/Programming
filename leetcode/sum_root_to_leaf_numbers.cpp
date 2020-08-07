class Solution {
public:
    int sumNumbers(TreeNode* root) {
        return recurse(0, root);
    }

    int recurse(int val, TreeNode* node) {
        if(node == NULL) return 0;
        else {
            if(node->left == NULL && node->right == NULL) {
                return val*10 + node->val;
            } else {
                return recurse((val*10 + node->val), node->left) + recurse((val*10 + node->val), node->right);
            }
        }
    }
};