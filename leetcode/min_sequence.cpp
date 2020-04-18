class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        vector<int> res;
        sort(nums.begin(), nums.end());
        int tot = 0;
        for (int i = 0; i < nums.size(); i++) tot += nums[i];
        
        int r = 0;
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (r > tot) break;
            else {
                int a = nums[i];
                res.push_back(a);
                tot -= a;
                r += a;
            }
        }
        return res;
    }
};