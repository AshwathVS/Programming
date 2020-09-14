class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size=nums.size();
        vector<int> prefix(size, 1), suffix(size, 1);
        int start = nums[0];
        for(int i=1; i<size; i++) {
            prefix[i] = start;
            start*=nums[i];
        }
        start=nums[size-1];
        for(int i=size-2; i>=0; i--) {
            suffix[i]=start;
            start*=nums[i];
        }
        
        vector<int> res(size, 0);
        for(int i=0; i<size; i++) {
            res[i] = prefix[i] * suffix[i];
        }
        
        return res;
    }
};