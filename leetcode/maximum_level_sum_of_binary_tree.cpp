class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        int level = 1, sum = INT_MIN, res_level = 1;
        q.push(root);
        
        
        while(!q.empty()) {
            int size = q.size();
            int t_sum = 0;
            for(int i=0; i<size; i++) {
                TreeNode* top = q.front();
                q.pop();
                t_sum += top->val;
                if(top->left != NULL) q.push(top->left);
                if(top->right != NULL) q.push(top->right);
            }
            if(t_sum > sum) {
                sum = t_sum;
                res_level = level;
            }

            level++;
        }
        return res_level;        
    }
};