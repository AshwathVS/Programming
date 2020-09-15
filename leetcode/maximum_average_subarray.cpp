class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int max = INT_MIN;
        int end = k-1;

        int sum = 0;

        for(int i=0; i<=end; i++) {
            sum+=nums[i];
        }

        while(true) {
            if(sum > max) max = sum;
            sum -= (nums[end-k+1]);
            end++;
            if(end == nums.size()) break;
            sum += nums[end];
        }

        return (double)max/k;
    }
};