class Solution {
public:
    int row, col;

    int dp(int i, int j, vector<vector<int>>& store, vector<vector<int>>& grid) {
        if(i == row || j == col) return -1;
        else if(i == row-1 && j == col-1) return grid[i][j];
        else if(store[i][j] != -1) return store[i][j];
        else {
            int val = grid[i][j];
            int right = dp(i, j+1, store, grid);
            int down = dp(i+1, j, store, grid);

            if(right >= 0 && down >= 0) {
                val = min(right, down) + val;
            } else if(right >= 0) {
                val += right;
            } else {
                val += down;
            }

            store[i][j] = val;
            return store[i][j];
        }
    }

    int minPathSum(vector<vector<int>>& grid) {
        row = grid.size();
        col = grid[0].size();

        vector<vector<int>> store(row);

        for(int i=0; i<row; i++) store[i] = vector<int>(col, -1);

        return dp(0, 0, store, grid);
    }
};