class Solution {
public:
    int getIndex(vector<int> nums, int index) {
        if(index < 0) return INT_MIN;
        else if (index >= nums.size()) return INT_MAX;
        else return nums[index];
    }

    bool checkPossibility(vector<int>& nums) {
        bool chance = true;
        int size=nums.size();

        for(int i=0; i<size-1; i++) {
            if(nums[i] > nums[i+1]) {
                if(!chance) return false;

                // try to change nums[i]
                if(getIndex(nums, i-1) <= nums[i+1]) {
                    nums[i] = nums[i+1];
                    chance = false;
                }

                // try to change nums[i+1]
                if(getIndex(nums, i+2) >= nums[i]) {
                    nums[i+1] = nums[i];
                    chance = false;
                }
                
                if(chance) return false;

            }
        }

        return true;
    }
};