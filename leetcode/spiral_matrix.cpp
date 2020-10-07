class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if(matrix.size() == 0) return res;

        int r = matrix.size()-1;
        int c = matrix[0].size()-1;
        int total = (r+1)*(c+1);
		
		// left_t_c -> left top corner
		// left_b_c -> left bottom corner
		// right_t_c -> right top corner
		// right_b_c -> right bottom corner
		
        pair<int, int> left_t_c{0, 0}, left_b_c{r, 0}, right_t_c{0, c}, right_b_c{r, c};

        while(res.size() < total) {

            // top row
            for(int i=left_t_c.second; i<=right_t_c.second; i++) {
                res.push_back(matrix[left_t_c.first][i]);
            }

            // right column
            for(int i=right_t_c.first+1; i<=right_b_c.first; i++) {
                res.push_back(matrix[i][right_t_c.second]);
            }

            // bottom row
            if(left_t_c.first != right_b_c.first) {
                for(int i=right_b_c.second-1; i>=left_b_c.second; i--) {
                    res.push_back(matrix[right_b_c.first][i]);
                }
            }

            // left column
            if(right_t_c.second != left_b_c.second) {
                for(int i=left_b_c.first-1; i>left_t_c.first; i--) {
                    res.push_back(matrix[i][left_b_c.second]);
                }
            }


            left_t_c = {left_t_c.first+1, left_t_c.second+1};
            left_b_c = {left_b_c.first-1, left_b_c.second+1};
            right_t_c = {right_t_c.first+1, right_t_c.second-1};
            right_b_c = {right_b_c.first-1, right_b_c.second-1};
        }

        return res;
    }
};
