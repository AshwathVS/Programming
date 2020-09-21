class Solution {
public:
    vector<vector<char>> board;
    string word;
    vector<vector<bool>> visited;
    vector<pair<int, int>> movement = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    int row, col;

    bool init(int i, int j, int index) {
        if(board[i][j] == word[index]) {
            if(index == word.size()-1) return true;
            for(pair<int, int> move : movement) {
                int new_i=i+move.first;
                int new_j=j+move.second;
                bool validIndex = ((new_i >= 0 && new_i < row) && (new_j >= 0 && new_j < col));
                if(validIndex && !visited[new_i][new_j]) {
                    visited[new_i][new_j] = true;
                    if(init(new_i, new_j, index + 1)) return true;
                    visited[new_i][new_j] = false;
                }
            }
        }
        return false;
    }

    bool exist(vector<vector<char>>& b, string w) {
        board = b;
        word = w;

        row=board.size();
        col = board[0].size();

        for(int i=0; i<row; i++) {
            visited.push_back(vector<bool>(board[0].size(), false));
        }

        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                if(board[i][j] == word[0]) {
                    visited[i][j] = true;
                    if(init(i, j, 0)) return true;
                    visited[i][j] = false;
                }
            }
        }

        return false;
    }

};