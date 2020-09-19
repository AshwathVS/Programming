class Solution {
public:    
    void rotate(vector<vector<int>>& m) {
        int size = m.size(), tmp;
        for(int i=0; i<size; i++) {
            for(int j=0; j<=i; j++) {
                tmp = m[i][j];
                m[i][j] = m[j][i];
                m[j][i] = tmp;
            }
        }
        
        
        for(int i=0; i<size; i++) {
            int left=0, right=size-1;
            
            while(left < right) {
                tmp = m[i][left];
                m[i][left] = m[i][right];
                m[i][right] = tmp;
                left++;
                right--;
            }
        }
    }
};