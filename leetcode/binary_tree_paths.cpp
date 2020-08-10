
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        recurse(root, res, "");
        return res;
    }
    
    void recurse(TreeNode* root, vector<string>& res, string str) {
        if(root != NULL) {
            if(root->left == NULL && root->right == NULL) {
                res.push_back(str + to_string(root->val));
            } else {
                recurse(root->left, res, str + to_string(root->val) + "->");
                recurse(root->right, res, str + to_string(root->val) + "->");
            }
        }
    }
};