class BSTIterator {
public:
    
    vector<int> v;
    int index=0;
    
    BSTIterator(TreeNode* root) {
        initInOrderTraversal(root);
    }
    
    void initInOrderTraversal(TreeNode* node) {
        if(node != NULL) {
            initInOrderTraversal(node->left);
            v.push_back(node->val);
            initInOrderTraversal(node->right);
        }
    }
    
    /** @return the next smallest number */
    int next() {
        return v[index++];
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return index < v.size();
    }
};