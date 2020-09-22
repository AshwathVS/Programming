class Solution {
public:
    
    int recurse(vector<int>& dp, int n) {
        if(dp[n] != -1) return dp[n];
        else {
            int cnt = 0;
            for(int i=1; i<=n; i++) {
                if(i == 1 || i == n) cnt+=recurse(dp, n-1);
                else {
                    cnt+=(recurse(dp, i-1) * recurse(dp, n-i));
                }
            }
            dp[n] = cnt;
            return cnt;
        }
    }
    
    int numTrees(int n) {
        vector<int> dp(20, -1);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 5;

        return recurse(dp, n);
    }
};