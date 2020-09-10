class Solution {
public:
    bool canReach(int index, int val, int size) {
        return index + val >= size;
    }
    
    bool recurse(vector<int> nums, vector<int>& dp, int index) {
        if(dp[index] == -1) {
            if(index + nums[index] >= nums.size()) {
                dp[index] = true;
            } else {
                int right=index+nums[index];
                bool canReach = false;
                while(right > index) {
                    cout << index << " - " << right << endl;
                    if(recurse(nums, dp, right)) {
                        canReach=true;
                        break;
                    }
                    right--;
                }

                dp[index] = canReach;
            }
        }
      
        return dp[index] == 1;
    }
    
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        if(nums.size() > 0) {
          dp[nums.size() - 1] = 1;
        }
        return recurse(nums, dp, 0);
    }
};