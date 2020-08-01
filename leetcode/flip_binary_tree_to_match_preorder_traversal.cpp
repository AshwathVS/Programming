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
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        vector<int> result;
        recurse(root, voyage, 0, result);
        return result;
    }
    
    int recurse(TreeNode* root, vector<int>& voyage, int index, vector<int>& result) {
        if(root == NULL) return index;
        if(root->val == voyage[index]) {
            index++;
            if(index == voyage.size()) return index;
            if(root->left == NULL && root->right == NULL) return index;
            if(root->left != NULL && root->left->val == voyage[index]) {
                index = recurse(root->left, voyage, index, result);
                if(index == -1) return index;
                return recurse(root->right, voyage, index, result);
            } else if(root-> right != NULL && root->right->val == voyage[index]) {
                if(root->left != NULL) result.push_back(root->val);
                index = recurse(root->right, voyage, index, result);
                if(index == -1) return index;
                return recurse(root->left, voyage, index, result);
            }
        }
        result = vector<int> {-1};
        return -1;
    }
};