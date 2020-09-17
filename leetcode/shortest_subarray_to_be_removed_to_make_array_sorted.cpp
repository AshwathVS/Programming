class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& nums) {
        int rr = 0;
        int size = nums.size();

        for(int i = size - 2; i >= 0; i--) {
            if(nums[i] > nums[i + 1]) {
                rr = i + 1;
                break;
            }
        }
        int res = rr;
        for(int ll=0; ll<rr && (ll == 0 || (nums[ll] >= nums[ll-1])); ll++) {
            while (rr < size && nums[rr] < nums[ll]) rr++;
            res = min(res, rr-ll-1);
        }

        return res;
    }
};