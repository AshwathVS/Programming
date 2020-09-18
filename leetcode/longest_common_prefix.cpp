class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) return "";

        string lcp = strs[0];

        for(string s : strs) {
            if(lcp == s) continue;
            
            for(string s : strs) {
                if(lcp == s) continue;

                int i=0;
                for(; (i<lcp.size() && i<s.size()); i++) {
                    if(lcp[i] != s[i]) {
                        break;
                    }
                }
                lcp = lcp.substr(0, i);

                if(lcp == "") break;
            }
            
            if(lcp == "") break;
        }

        return lcp;
    }
};
