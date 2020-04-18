class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        
        
        int counter = 1;        
        int prev = nums[0];
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != prev) {
                nums[counter] = nums[i];
                counter++;
                prev = nums[i];
            }
        }
        return counter;
    }
};