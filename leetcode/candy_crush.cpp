class Solution {
public:
    vector<vector<int>> candyCrush(vector<vector<int>>& board) {
        int r = board.size();
        int c = board[0].size();

        bool repeat = false;

        do {
            repeat = false;
            for(int i=0; i<r; i++) {
                for(int j=1; j<c-1; j++) {
                    int val = abs(board[i][j]);
                    if(val != 0 && val == abs(board[i][j-1]) && val == abs(board[i][j+1])) {
                        board[i][j] = -val;
                        board[i][j-1] = -val;
                        board[i][j+1] = -val;
                        repeat = true;
                    }
                }
            }

            for(int i=1; i<r-1; i++) {
                for(int j=0; j<c; j++) {
                    int val = abs(board[i][j]);
                    if(val != 0 && val == abs(board[i-1][j]) && val == abs(board[i+1][j])) {
                        board[i][j] = -val;
                        board[i+1][j] = -val;
                        board[i-1][j] = -val;
                        repeat = true;
                    }
                }
            }

            for(int col = 0; col<c; col++) {
                int baseIndex = r - 1;
                for (int row = r - 1; row >= 0; row--) {
                    if(board[row][col] > 0) {
                        board[baseIndex--][col] = board[row][col];
                    }
                }

                while(baseIndex >= 0) {
                    board[baseIndex--][col] = 0;
                }
            }
        } while (repeat);

        return board;
    }
};