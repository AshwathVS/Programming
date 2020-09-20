class Solution {
public:
    int store[101][101];
    int row, col;
    vector<vector<int>> grid;

    void sett() {
        for(int i=0; i<row; i++)
            for(int j=0; j<col; j++)
                store[i][j] = -1;
    }

    int dynamic(int i, int j) {
        if(i >= row || j >= col) return 0;
        else if(grid[i][j] == 1) return 0;
        else if(i == row-1 && j == col-1) return 1;
        else if(store[i][j] != -1) return store[i][j];
        else {
            int right = dynamic(i, j+1);
            int down = dynamic(i+1, j);
            int sum = right+down;
            store[i][j] = sum;
            return sum;
        }
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        grid = obstacleGrid;
        row = grid.size();
        col = grid[0].size();
        sett();
        return dynamic(0, 0);
    }
};