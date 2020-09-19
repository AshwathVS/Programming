class Solution {
public:
    vector<int> nums;
    vector<vector<int>> res;
    int len;
    int target;

    void recurse(vector<int> lst, int currentSum, int start) {
        for(int i : lst) cout << i << " ";
        cout << endl;

        if(currentSum == target) res.push_back(lst);
        else if(currentSum > target) return;
        else {
            while(start < len && currentSum + nums[start] <= target) {
                lst.push_back(nums[start]);
                recurse(lst, currentSum + nums[start], start);
                lst.pop_back();
                start++;
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int tar) {
        nums = candidates;
        sort(nums.begin(), nums.end());
        len = nums.size();
        target = tar;
        recurse({}, 0, 0);
        return res;
    }
};