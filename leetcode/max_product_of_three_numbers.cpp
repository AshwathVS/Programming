class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int a = INT_MIN, b = INT_MIN, c = INT_MIN;
        int d = INT_MAX, e = INT_MAX;

        for(int i=0; i<nums.size(); i++) {
            if(nums[i] >= a) {
                c=b;
                b=a;
                a=nums[i];
            } else if (nums[i] >= b) {
                c=b;
                b=nums[i];
            } else if(nums[i] > c) {
                c=nums[i];
            }

            if(nums[i] <= d) {
                e = d;
                d = nums[i];
            } else if(nums[i] <= e) {
                e = nums[i];
            }
        }

        return max(a * b * c, a * d * e);
    }
};