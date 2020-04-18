class Solution {
public:
    // 00001111
    void moveZeroes(vector<int>& nums) {
        int zero = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                if (zero == -1) continue;
                else {
                    int tmp = nums[i];
                    nums[i] = 0;
                    nums[zero] = tmp;
                    zero++;
                }
            }
            else if (nums[i] == 0 && zero == -1) zero = i;
        }
    }
};