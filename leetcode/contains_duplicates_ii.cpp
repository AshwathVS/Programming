class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, int> st;
        for(int i=0; i<nums.size(); i++) {
            if(st.find(nums[i]) == st.end()) {
                st.insert({nums[i], i});
            } else {
                if(abs(st[nums[i]] - i) <= k) return true;
                
                st[nums[i]] = i;
            }
        }
        
        return false;
    }
};