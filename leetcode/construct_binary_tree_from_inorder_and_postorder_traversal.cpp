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

    vector<int> in, post;

    int indexOf(vector<int>& arr, int data) {
        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] == data) return i;
        }
        return -1;
    }

    TreeNode* build(int index, int left, int right) {
        if(left == right) return new TreeNode(in[left]);

        else if (left > right) return NULL;

        TreeNode* root = new TreeNode(post[index]);
        int rootIndex = indexOf(in, post[index]);
        TreeNode* rightT = build(index-1, rootIndex+1, right);
        TreeNode* leftT = build(index - (right-rootIndex+1), left, rootIndex-1);
        root->left = leftT;
        root->right = rightT;
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        in = inorder;
        post = postorder;
        int size=postorder.size();
        
        return build(size-1, 0, size-1);
    }

};