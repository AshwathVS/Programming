class Solution {
public:

    int minMeetingRooms(vector<vector<int>>& intervals) {
        if(intervals.size() == 0) return 0;

        sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b) {return (a[0] != b[0]) ? a[0] < b[0] : b[1] < a[1];});

        int res = 1;

        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(vector<int> interval : intervals) {
            if(pq.empty()) {
                pq.push(interval[1]);
            } else {
                if(pq.top() <= interval[0]) {
                    pq.pop();
                } else {
                    res++;
                }
                
                pq.push(interval[1]);
            }
        }

        return res;
    }
};