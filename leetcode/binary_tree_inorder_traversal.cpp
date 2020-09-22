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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> ss;

        TreeNode* curr = root;

        while(curr != NULL || !ss.empty()) {
            while(curr != NULL) {
                ss.push(curr);
                curr=curr->left;
            }
            
            curr = ss.top();
            ss.pop();
            res.push_back(curr->val);
            curr=curr->right;
        }

        return res;
    }
};