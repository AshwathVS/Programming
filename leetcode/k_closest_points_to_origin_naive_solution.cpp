class Solution {
public:
    
    static bool sortFunc(vector<int> a, vector<int> b) {
        double distA = (a[0] * a[0]) + (a[1] * a[1]);
        double distB = (b[0] * b[0]) + (b[1] * b[1]);
        return distA < distB;
    }
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        if(k >= points.size()) return points;
        else {
            vector<vector<int>> res;
            if(k == 0) return res;
            else {
                sort(points.begin(), points.end(), Solution::sortFunc);
                for(int i=0; i<k; i++) res.push_back(points[i]);
            }
            
            return res;
        }
    }
};