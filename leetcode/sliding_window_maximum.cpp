class Solution {
public:
    void process(vector<int> &nums, deque<int>& dq, int i) {
        while(!dq.empty() && nums[i] > nums[dq.back()]) dq.pop_back();
        dq.push_back(i);
    }

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        int i=0;
        for(int i=0; i<k; i++) {
            process(nums, dq, i);
        }

        vector<int> res;

        int start = 0, end = k-1;
        while(end < nums.size()) {
            res.push_back(nums[dq.front()]);

            // remove start
            // inc start
            // inc end
            // append end
            if(nums[dq.front()] == nums[start]) {
                dq.pop_front();
            }
            start++;
            end++;
            if(end < nums.size()) process(nums, dq, end);
        }

        return res;
    }
};