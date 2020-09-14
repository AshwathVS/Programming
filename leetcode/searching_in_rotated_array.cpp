class Solution {
public:
    int search(vector<int> nums, int target) {
        int low = 0, high = nums.size() - 1;

        if (low == high && nums[low] == target) return low;

        while (low <= high) {
            int mid = (low + high) / 2;

            if (nums[mid] == target) return mid;

            // if left side is sorted
            if(nums[low] <= nums[mid]) {
                if(target >= nums[low] && target <= nums[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else {
                // left is not sorted it is confirmed that right is sorted
                if(target > nums[mid] && target <= nums[high]) {
                    low = mid + 1;
                } else high = mid - 1;
            }
        }

        return -1;
    }
};