class Solution {

public:
    vector<long long> mods;
    int mod = 1000000007;

    void calculate(int max) {
        long long res = 1;
        mods.push_back(1);
        for(int i=1; i<max; i++) {
            mods.push_back((2 * mods[i - 1]) % mod);
        }
    }

    int numSubseq(vector<int>& nums, int target) {
        calculate(nums.size());
        sort(nums.begin(), nums.end());
        long long count = 0;

        int left = 0;
        int right = nums.size() - 1;

        while(left <= right) {
            if(nums[left] + nums[right] > target) right--;
            else {
                count += mods[right-left];
                left++;
            }
        }
        
        return count % 1000000007; 
    }

};
