class Solution {
public:

    bool isMerge(vector<int>& a, vector<int>& b) {
        return b[0] <= a[1];
    }

    vector<int> merge(vector<int>& a, vector<int>& b) {
        return {min(a[0], b[0]), max(a[1], b[1])};
    }

    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        const int _size = intervals.size();
        vector<vector<int>> res;

        int i=0;
        for(; i<_size; i++) {
            if(intervals[i][0] < newInterval[0]) res.push_back(intervals[i]);
            else break;
        }

        res.push_back(newInterval);

        if(res.size() > 1) {
            auto oneBeforeLast = res[res.size() - 2];
            auto last = res[res.size() - 1];
            if(isMerge(oneBeforeLast, last)) {
                vector<int> merged = merge(oneBeforeLast, last);
                res.pop_back();
                res.pop_back();
                res.push_back(merged);
            }
        }

        for(; i<_size; i++) {
            auto last = res[res.size() - 1];
            auto toAdd = intervals[i];
            if(isMerge(last, toAdd)) {
                res.pop_back();
                res.push_back(merge(last, toAdd));
            } else res.push_back(toAdd);
        }

        return res;
    }
};