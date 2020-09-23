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
    vector<vector<int>> res;

    void recurse(TreeNode* node, int sum, vector<int>& currentPath) {
        if(node == NULL) return;

        int val = node->val;
        if(val == sum) {
            if(node->left == NULL && node->right == NULL) {
                currentPath.push_back(val);
                res.push_back(currentPath);
                currentPath.pop_back();
                return;
            }
        }
        currentPath.push_back(val);

        if(node->left != NULL) recurse(node->left, sum-val, currentPath);
        if(node->right != NULL) recurse(node->right, sum-val, currentPath);

        currentPath.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> currentPath;
        recurse(root, sum, currentPath);
        return res;
    }
};