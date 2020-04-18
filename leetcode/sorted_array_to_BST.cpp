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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return recur(nums, 0, nums.size() - 1);
    }
    
    TreeNode* recur(vector<int>& nums, int left, int right) {
        if (left > right) {
            return NULL;
        } else {
            int mid = (left + right) / 2;
            TreeNode* curr = new TreeNode(nums[mid]);
            curr->left = recur(nums, left, mid - 1);   
            curr->right = recur(nums, mid + 1, right);
            
            return curr;
        }
    }
};