class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> mm;
        int count = 0;
        for(int i : nums) {
            mm[i]++;
        }
        
        for(pair<int, int> entry : mm) {
            if(k == 0) {
                if(entry.second > 1) count++;
            } else {
                if(mm.find(entry.first + k) != mm.end()) count++;
            }
        }
        
        return count;
    }
};
