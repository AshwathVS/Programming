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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        queue<pair<int, TreeNode*>> qq;
        vector<vector<int>> res;
        if(root == NULL) return res;

        qq.push({0, root});
        int min_col = INT_MAX, max_col=INT_MIN;
        unordered_map<int, vector<int>> mm;
        while(!qq.empty()) {
            pair<int, TreeNode*> pp = qq.front();
            qq.pop();
            
            mm[pp.first].push_back(pp.second->val);
            
            min_col = min(pp.first, min_col);
            max_col = max(pp.first, max_col);
            
            if(pp.second->left != NULL) {
                qq.push({pp.first - 1, pp.second->left});
            }
            
            if(pp.second->right != NULL) {
                qq.push({pp.first + 1, pp.second->right});
            }
        }
        
        for(int i=min_col; i<=max_col; i++) {
            res.push_back(mm[i]);
        }
        
        return res;
    }
};