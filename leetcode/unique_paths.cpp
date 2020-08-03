class Solution {
public:
    int store[101][101];
    
    void set() {
        for(int i=0; i<101; i++) {
            for(int j=0; j<101; j++) {
                store[i][j] = -1;
            }
        }
    }

    int dynamic(int i, int j, int m, int n) {
        if(i >= m || j >= n) return 0;
        else if(store[i][j] != -1) return store[i][j];
        else if(i+1 == m && j+1 == n) return 1;
        else {
            int right = dynamic(i, j + 1, m, n);
            int down = dynamic(i + 1, j, m, n);
            store[i][j] = right + down;
            return store[i][j];
        }
    }
    
    int uniquePaths(int m, int n) {
        set();
        return dynamic(0, 0, m, n);
    }
    
};