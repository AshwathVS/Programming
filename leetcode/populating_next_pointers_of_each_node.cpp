class Solution {
public:
    Node* getRight(Node* root) {
        if(root == NULL) return NULL;
        else if(root->left != NULL) return root->left;
        else if(root->right != NULL) return root->right;
        else return getRight(root->next);
    }
    
    void fill(Node* node, Node* root) {
        if(root == NULL) node->next = NULL;
        else if(root->right != NULL && root->right != node) {
            node->next = root->right;
        } else {
            node->next = getRight(root->next);
        }
        
        
        if(node->right != NULL) fill(node->right, node);
        if(node->left != NULL) fill(node->left, node);
    }

    Node* connect(Node* root) {
        if(root != NULL) fill(root, NULL);
        return root;
    }
};