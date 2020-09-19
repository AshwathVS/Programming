class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int size=nums.size();
        int left=0, right=size-1, mid;
        int left_most=INT_MAX, right_most=INT_MIN;

        // finding left most
        while(left <= right) {
            mid=(left+right)/2;
            if(nums[mid] == target) {
                left_most=min(left_most, mid);
                right=mid-1;
            } else if(nums[mid] > target) right=mid-1;
            else left = mid+1;
        }

        // finding right most
        if(left_most != INT_MAX) {
            left=0; right=size-1;
            while(left <= right) {
                mid=(left+right)/2;
                if(nums[mid] == target) {
                    right_most=max(right_most, mid);
                    left=mid+1;
                } else if(nums[mid] > target) right=mid-1;
                else left = mid+1;
            }
        }

        if(left_most == INT_MAX) return {-1, -1};
        else if(left_most == right_most) return {left_most, left_most};
        else return {left_most, right_most};
    }
};