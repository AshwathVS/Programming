// Union find approach mentioned in solution
class Solution {
public:
    vector<int> uf;

    int find(int a) {
        while(uf[a] != a) {
            a = uf[a];
        }

        return a;
    }

    void unionn(int a, int b) {
        int root_a = find(a);
        int root_b = find(b);
        uf[root_a] = root_b;
    }

    int regionsBySlashes(vector<string>& grid) {
        uf = vector<int>(4 * grid.size() * grid.size(), -1);
        for(int i=0; i<uf.size(); i++) uf[i] = i;

        int n = grid.size();

        for(int r=0; r<n; r++) {
            for(int c=0; c<n; c++) {
                int root = 4 * (r * n + c);
                if(grid[r][c] != '\\') {
                    unionn(root + 0, root + 3);
                    unionn(root + 2, root + 1);
                }

                if(grid[r][c] != '/') {
                    unionn(root + 0, root + 2);
                    unionn(root + 3, root + 1);
                }

                // union with cell on top
                if(r > 0) {
                    int top_root = 4 * ((r-1) * n + c);
                    unionn(root + 2, top_root + 3);
                }

                // union with cell on bottom
                if(r + 1 < n) {
                    int bot_root = 4 * ((r+1) * n + c);
                    unionn(root + 3, bot_root + 2);
                }

                // union with cell on left
                if(c > 0) {
                    int left_root = 4 * ((r * n) + (c-1));
                    unionn(root + 1, left_root + 0);
                }

                // union with cell on right
                if(c + 1 < n) {
                    int right_root = 4 * ((r*n) + (c + 1));
                    unionn(root + 0, right_root + 1);
                }
            }
        }

        int ans=0;
        for(int i=0; i<uf.size(); i++){
            if(uf[i] == i) ans++;
        }

        return ans;
    }
};