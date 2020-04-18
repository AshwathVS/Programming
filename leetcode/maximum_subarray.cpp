class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        } else {
            int r_sum = nums[0], max = nums[0];
            for(int i = 1; i < nums.size(); i++) {
                r_sum = custom_max(nums[i], r_sum + nums[i]);
                max = custom_max(max, r_sum);
            }
            
            return max;
        }
    }
    
    
    int custom_max(int a, int b) {
        if (a > b) {
            return a;
        } else {
            return b;
        }
    }
};