class Solution {
public:
    static bool sortFunc(vector<int> a, vector<int> b) {
        if(a[0] == b[0]) return a[1] < b[1];
        else return a[0] < b[0];
    }

    bool isMerge(vector<int> a, vector<int> b) {
        if(b[0] < a[0]) {
            vector<int> c = a;
            a = b;
            b = c;
        }
        
        return (b[0] >= a[0] && b[0] <= a[1]);
    }
    
    vector<int> merge(vector<int> a, vector<int> b) {
        if(b[0] < a[0]) {
            vector<int> c = a;
            a = b;
            b = c;
        }

        return vector<int> {a[0], a[1] > b[1] ? a[1] : b[1]};
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        sort(intervals.begin(), intervals.end(), sortFunc);
        if(intervals.size() > 0) {
            vector<int> prev = intervals[0];
            for(int i = 0; i < intervals.size(); i++) {
                if(isMerge(prev, intervals[i])) {
                    prev = merge(prev, intervals[i]);
                    if(result.size() > 0) {
                        result.pop_back();
                    }
                }
                else {
                    prev = intervals[i];
                }
                result.push_back(prev);
            }
        }

        return result;
    }
};