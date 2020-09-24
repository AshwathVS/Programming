class Solution {
public:
    vector<vector<int>> dp;

    int recurse(int row, int index, vector<vector<int>>& triangle) {
        if(row == triangle.size()) return 0;
        else if(dp[row][index] != INT_MAX) return dp[row][index];
        else {
            int val = triangle[row][index];

            int left = recurse(row+1, index, triangle);
            int right = recurse(row+1, index+1, triangle);
            dp[row][index] = val + min(left, right);
            return dp[row][index];
        }
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        for(int i=0; i<triangle.size(); i++) {
            dp.push_back(vector<int>(triangle[i].size(), INT_MAX));
        }
        return recurse(0, 0, triangle);
    }

};