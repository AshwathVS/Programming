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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == NULL) return {};

        queue<TreeNode*> qq;
        bool invert = false;
        vector<vector<int>> res;
        qq.push(root);
        
        while(!qq.empty()) {
            int n = qq.size();
            vector<int> v;
            while(n--) {
                auto x = qq.front();
                qq.pop();
                
                TreeNode* left = x->left;
                TreeNode* right = x->right;

                if(left != NULL) qq.push(left);
                if(right != NULL) qq.push(right);

                if(invert) {
                    v.insert(v.begin(), x->val);
                } else {
                    v.push_back(x->val);
                }
            }

            invert = !invert;
            res.push_back(v);
        }
        
        return res;
    }
};