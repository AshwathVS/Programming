class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        set<pair<int, int>> sums;
        int size = nums.size();

        if(nums.size() > 2) {
            sort(nums.begin(), nums.end());
            
            for(int i=0; i<size-1; i++) {
                int left = 0;
                int right = size-1;
                
                while(left < i && right > i) {
                    int sum=nums[left] + nums[right] + nums[i];
                    if(sum == 0) {
                        sums.insert({nums[left], nums[i]});
                        left++;
                        right--;
                    } else if (sum > 0) {
                        right--;
                    } else {
                        left++;
                    }
                }
            }
        }

        for(pair<int, int> i : sums) {
            res.push_back({i.first, i.second, -(i.first+i.second)});
        }

        return res;
    }
};