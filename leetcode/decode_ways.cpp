class Solution {
public:
    int size;

    int recurse(int index, string s, vector<int>& dp) { 
        if(index == size) return 1;
        else if(dp[index] != -1) return dp[index];
        else if(s[index] == '0') {
            dp[index]=0;
            return dp[index];
        }
        else {
            int single = recurse(index+1, s, dp), coupled=0;
            
            int xx = s[index]-'0';
            int yy = s[index+1]-'0';
            
            // check if we can couple
            if((xx == 1) || (xx == 2 && yy < 7)) {
                coupled = recurse(index+2, s, dp);
            }
            
            dp[index] = single+coupled;
            return dp[index];
        }
    }

    int numDecodings(string s) {
        vector<int> dp(s.size(), -1);
        size = s.size();

        dp[size-1] = s[size-1]-'0' ? 1 : 0;

        return recurse(0, s, dp);

    }
};