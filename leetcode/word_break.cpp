class Solution {
public:
    bool recurse(set<string>& ss, vector<int>& dp, int index, string s) {
        if(index == s.size()) return true;
        else if(dp[index] != -1) return dp[index];
        else {
            bool res = false;
            string runningStr = "";
            for(int i=index; i<s.size(); i++) {
                runningStr += s[i];
                if(ss.find(runningStr) != ss.end()) {
                    res = recurse(ss, dp, i+1, s);
                }
                if(res) break;
            }

            dp[index]=res;
            return dp[index];
        }
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> ss;
        for(auto str : wordDict) ss.insert(str);
        vector<int> dp(s.size(), -1);

        return recurse(ss, dp, 0, s);
    }
};