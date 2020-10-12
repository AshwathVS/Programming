class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(begin(costs), end(costs), [](vector<int>& a, vector<int>& b) {
            return (a[1] - a[0]) > (b[1] - b[0]);
        });

        int res = 0, half_size = costs.size()/2;
        for(int i=0; i<half_size; i++) {
            res += costs[i][0] + costs[i+half_size][1];
        }
        return res;
    }
};