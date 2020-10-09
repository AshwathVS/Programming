class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixSum;
        
        int sum = 0, count=0;
        prefixSum.insert({0, 1});

        for(int i=0; i<nums.size(); i++) {
            sum+=nums[i];
            
            if(prefixSum.find(sum-k) != prefixSum.end()) {
                count += prefixSum[sum-k];
            }
            
            prefixSum[sum]++;
        }

        return count;
    }

};