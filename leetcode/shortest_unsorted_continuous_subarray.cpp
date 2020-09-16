class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        bool disorder = false;
        int minn = INT_MAX, maxx = INT_MIN;

        for(int i=1; i<nums.size(); i++) {
            if(nums[i] < nums[i-1]) disorder = true;
            
            if(disorder) {
                minn = min(minn, nums[i]);
            }
        }
        
        disorder = false;
        for(int i=nums.size() - 2; i >=0; i--) {
            if(nums[i] > nums[i+1]) disorder = true;
            
            if(disorder) {
                maxx = max(maxx, nums[i]);
            }
        }
        
        if(minn == INT_MAX) return 0;
        else {
            int left = 0, right = nums.size() - 1;
            while(nums[left] <= minn) left++;
            while(nums[right] >= maxx) right--;
            return right - left + 1;
        }
    } 
};