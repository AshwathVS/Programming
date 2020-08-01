class Solution {
public:
    
    int indexOf(vector<int>& arr, int data) {
        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] == data) return i;
        }
        return -1;
    }

    TreeNode* recurse(vector<int>& preorder, vector<int>& inorder, int index, int left, int right) {
        if (left > right) {
            return NULL;
        } else if (left == right) {
            return new TreeNode(inorder[left]);
        } else {
            TreeNode *root = new TreeNode(preorder[index]);

            int rootIndex = indexOf(inorder, preorder[index]);

            TreeNode *leftNode = recurse(preorder, inorder, index + 1, left, rootIndex - 1);
            TreeNode *rightNode = recurse(preorder, inorder, index + (rootIndex - left) + 1, rootIndex + 1, right);

            root->left = leftNode;
            root->right = rightNode;
            return root;
        }
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return recurse(preorder, inorder, 0, 0, inorder.size() - 1);
    }

};