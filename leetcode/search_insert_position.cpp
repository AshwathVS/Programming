class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {       
        return binarySearch(nums, target, 0, nums.size() - 1);
    }
    
    
    int binarySearch(vector<int>& nums, int target, int i, int j) {
        int mid = (i + j) / 2;
        if (target == nums[mid]) {
            return mid;
        } else if (i == j) {
            if (target > nums[i]) {
                return i + 1;
            } else {
                return i;
            }
        } else if (target < nums[mid]) {
            return binarySearch(nums, target, i, mid);
        } else {
            return binarySearch(nums, target, mid + 1, j);
        }
    }
    
};