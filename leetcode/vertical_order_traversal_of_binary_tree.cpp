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
    void traverse(TreeNode* node, int position, int level, map<int, vector<pair<int, int>>>& mm) {
        if(node == NULL) return;

        mm[position].push_back({level, node->val});
        traverse(node->left, position-1, level+1, mm);
        traverse(node->right, position+1, level+1, mm);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(root == NULL) return {};

        map<int, vector<pair<int, int>> > mm;
        traverse(root, 0, 0, mm);
        vector<vector<int>> res;
        for(auto it : mm) {
            vector<int> tmp;

            sort(it.second.begin(), it.second.end(), [](pair<int, int> a, pair<int, int> b) {
                return a.first == b.first ? a.second < b.second : a.first < b.first;
            });
            
            for(pair<int, int> entry : it.second) {
                tmp.push_back(entry.second);
            }

            res.push_back(tmp);
        }
        return res;
    }
};