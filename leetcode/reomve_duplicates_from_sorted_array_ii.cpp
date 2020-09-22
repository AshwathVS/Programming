class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() <= 2) return nums.size();

        int prev=nums[0], res=1, counter=1;

        for(int i=1; i<nums.size(); i++) {
            if(nums[i] != prev) {
                nums[res] = nums[i];
                counter=1;
                res++;
            } else {
                if(counter < 2) {
                    nums[res] = nums[i];
                    res++;
                    counter++;
                }
            }
            prev=nums[i];
        }
        return res;
    }
};