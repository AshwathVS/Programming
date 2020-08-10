class Solution {
public:
    string smallestFromLeaf(TreeNode* root) {
        return recurse(root, "");
    }
    
    string recurse(TreeNode* node, string init) {
        if(node == NULL) return init;
        else {
            string tmp = char('a' + node->val) + init;
            string left = recurse(node->left, tmp);
            string right = recurse(node->right, tmp);
            if(left == tmp) return right;
            if(right == tmp) return left;
            else return min(left, right);
        }
    }
};
