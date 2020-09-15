class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        set<pair<int, int>> pairs;
        
        int left=0, right=1;
        
        while(left < nums.size() && right < nums.size()) {
            int lt = nums[left];
            int rt = nums[right];
            int diff=abs(lt - rt);

            if(diff == k) {
                int minn = min(lt, rt);
                pairs.insert({minn, lt + rt - minn});
                left++;
                right++;
            } else if (diff < k) {
                right++;
            } else if (diff > k) {
                if(left + 1 == right) {
                    right++;
                }
                left++;
            }
        }

        return pairs.size();
    }
};