class Solution {
public:
    vector<TreeNode*> allPossibleFBT(int N) {
        if(N % 2 == 0) return {};
        else if(N == 1) return {new TreeNode(0, NULL, NULL)};
        else {
            vector<TreeNode*> res;
            for(int i=1; i<N; i+=2) {
                vector<TreeNode*> left = allPossibleFBT(i);
                vector<TreeNode*> right = allPossibleFBT(N-i-1);


                for(TreeNode* l_node : left) {
                    for(TreeNode* r_node : right) {
                        TreeNode* root = new TreeNode(0, l_node, r_node);
                        res.push_back(root);
                    }
                }
            }

            return res;
        }
    }
};