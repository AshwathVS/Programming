class Solution {
public:
    
    bool canJump(vector<int>& nums) {
        int size=nums.size();
        int lastIndex = size-1;
        for(int i=size-1; i>=0; i--) {
            if(i + nums[i] >= lastIndex) lastIndex=i;
        }
        
        return lastIndex == 0;
    }
};