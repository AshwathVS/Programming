class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int size=nums.size(), tmp;
        int ii=size-2;

        while(ii >= 0 && nums[ii+1] <= nums[ii]) ii--;

        if(ii >= 0) {
            int tt=size-1;
            while(tt > ii && nums[tt] <= nums[ii]) tt--;

            tmp=nums[ii];
            nums[ii]=nums[tt];
            nums[tt]=tmp;
        }
        // reverse ii+1, size-1
        int end=size-1;
        ii++;
        while(end > ii) {
            tmp = nums[end];
            nums[end] = nums[ii];
            nums[ii] = tmp;

            end--;
            ii++;
        }
    }
};
