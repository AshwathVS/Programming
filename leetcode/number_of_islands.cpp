class Solution {
public:
    vector<vector<char>> grid;
    vector<vector<bool>> seen;
    int rows, cols;
    
    bool validIndex(int i, int j) {
        return i >= 0 && i < rows && j >= 0 && j < cols;
    }
    
    void visitIsland(int _i, int _j) {
        int x, y, i, j;

        queue<pair<int, int>> q;
        q.push({_i, _j});
        seen[_i][_j] = true;
        
        while(!q.empty()) {
            auto front = q.front();
            q.pop();

            i = front.first;
            j = front.second;


            //left
            x=i;
            y=j-1;
            if(validIndex(x, y) && grid[x][y] != '0' && !seen[x][y]) {
                seen[x][y] = true;
                q.push({x, y});
            }
            
            // right
            x=i;
            y=j+1;
            if(validIndex(x, y) && grid[x][y] != '0' && !seen[x][y]) {
                seen[x][y] = true;
                q.push({x, y});
            }
            
            // up
            x=i-1;
            y=j;
            if(validIndex(x, y) && grid[x][y] != '0' && !seen[x][y]) {
                seen[x][y] = true;
                q.push({x, y});
            }

            // down
            x=i+1;
            y=j;
            if(validIndex(x, y) && grid[x][y] != '0' && !seen[x][y]) {
                seen[x][y] = true;
                q.push({x, y});
            }
        }
    }
    
    int numIslands(vector<vector<char>>& _grid) {
        if(_grid.size() == 0) return 0;

        grid = _grid;
        rows = grid.size();
        cols = grid[0].size();

        seen = vector<vector<bool>>(rows, vector<bool>(cols, false));

        int count = 0;

        for(int i=0; i<rows; i++) {
            for(int j=0; j<cols; j++) {
                if(!seen[i][j] && grid[i][j] == '1') {
                    count++;
                    visitIsland(i, j);
                }
            }
        }
        
        return count;
    }
};