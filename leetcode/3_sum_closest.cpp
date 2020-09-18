class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int size = nums.size();
        int closest = INT_MAX;
        int ressum;

        if(nums.size() > 2) {
            sort(nums.begin(), nums.end());

            for(int i=0; i<size-1; i++) {
                int left = 0;
                int right = size-1;

                while(left < i && right > i) {
                    int sum=nums[left] + nums[right] + nums[i];
                    int diff = abs(target-sum);
                    if(diff<closest) {
                        closest = diff;
                        ressum=sum;
                    }
                    
                    if(sum == target) return sum;
                    else if(sum < target) left++;
                    else right--;
                }
            }
        }

        return ressum;
    }
};