class Solution {
public:
    
    void recurse(vector<vector<int>>& res, vector<int>& subset, vector<int>& nums, int start) {
        if(start == nums.size()) res.push_back(subset);
        else {
            // do not pick this element
            recurse(res, subset, nums, start+1);

            // pick this element
            subset.push_back(nums[start]);
            recurse(res, subset, nums, start+1);
            subset.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;
        recurse(res, subset, nums, 0);
        return res;
    }

};