class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size=nums.size();
        vector<int> res(size, 1);

        for(int i=1; i<size; i++) {
            res[i] = res[i-1]*nums[i-1];
        }
        
        int suffix=1;
        for(int i=size-1; i>=0; i--) {
            res[i] = suffix*res[i];
            suffix*=nums[i];
        }
        
        return res;
    }
};