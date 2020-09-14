class Solution {
public:
    int thirdMax(vector<int> nums) {
        int max1=INT_MIN, max2=INT_MIN, max3=INT_MIN;
        bool max3_seen=false;

        for(int i=0; i< nums.size(); i++) {
            if(nums[i] > max1) {
                max3=max2;
                max2=max1;
                max1=nums[i];
            } else if(nums[i] > max2) {
                if(nums[i] != max1) {
                    if(max2 != max3) max3_seen = true;
                    max3=max2;
                    max2=nums[i];
                }
            } else if(nums[i] > max3) {
                if(nums[i] != max2) {
                    max3=nums[i];
                    max3_seen = true;
                }
            }
        }

        if(max3_seen) return max3;
        else return max1;
    }
};