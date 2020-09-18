class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        map<pair<int, int>, set<int>> mm;
        int size = nums.size();
        if(size < 4) return {};

        sort(nums.begin(), nums.end());

        for(int i=1; i<size-2; i++) {
            for(int j=i+1; j<size-1; j++) {
                int left=0, right=size-1;

                while(left < i && right > j) {
                    int sum = nums[left] + nums[i] + nums[j] + nums[right];

                    if(sum > target) right--;
                    else if(sum < target) left++;
                    else {
                        if(mm.find({nums[left], nums[i]}) != mm.end()) {
                            mm[{nums[left], nums[i]}].insert(nums[j]);
                        } else {
                            mm.insert({{nums[left], nums[i]}, {nums[j]}});
                        }

                        left++;
                        right--;
                    }
                }
            }
        }

        vector<vector<int>> res;

        for(auto i : mm) {
            for(int x : i.second) {
                int fourth = target - (i.first.first + i.first.second + x);
                res.push_back({i.first.first, i.first.second, x, fourth});
            }

        }

        return res;
    }
};