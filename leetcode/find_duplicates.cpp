class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        nums.insert(nums.begin(), 0);

        vector<int> res;

        for(int i=1; i<nums.size(); i++) {
            if(nums[i] == i) continue;
            else {
                int tmp = nums[i];
                if(tmp == -1) continue;
                while(true) {
                    if(tmp == -1) break;
                    int ele = tmp;
                    tmp = nums[ele];
                    if (tmp == ele) {
                        res.push_back(ele);
                        nums[ele] = -1;
                        break;
                    } else {
                        int prev = nums[i];
                        nums[ele] = ele;
                        if(prev != -1) nums[i] = -1;
                    }
                }
            }
        }
        return res;
    }

};