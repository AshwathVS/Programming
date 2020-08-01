class Solution {
public:
    
    vector<pair<int, int>> getAdjacentCells(int x, int y, int rows, int columns) {
        vector<pair<int, int>> cells{make_pair(-1, 0), make_pair(1, 0), make_pair(0, 1), make_pair(0, -1)};
        vector<pair<int, int>> result;
        
        for(pair<int, int> i : cells) {
            int _x = i.first + x;
            int _y = i.second + y;
            if(_x >= 0 && _x < rows && _y >= 0 && _y < columns) result.push_back(make_pair(_x, _y));
        }
        
        return result;
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> rotten;
        int fresh_count = 0;
        int iterations = 0;
        int rows = grid.size();
        int columns = grid[0].size();

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < columns; j++) {
                if(grid[i][j] == 2) rotten.push(make_pair(i, j));
                else if(grid[i][j] == 1) fresh_count++;
            }   
        }
        
        while(fresh_count > 0 && rotten.size() > 0) {
            rotten.push(make_pair(-1, -1));

            while(true) {
                pair<int, int> index = rotten.front();
                rotten.pop();
                if(index.first == -1) break;
                vector<pair<int, int>> adjCells = getAdjacentCells(index.first, index.second, rows, columns);
                for(pair<int, int> cell: adjCells) {
                    if(grid[cell.first][cell.second] == 1) {
                        fresh_count--;
                        grid[cell.first][cell.second] = 2;
                        rotten.push(cell);
                    }
                }
            }

            iterations++;
        }
        
        if(fresh_count == 0) return iterations;
        else return -1;
    }
};