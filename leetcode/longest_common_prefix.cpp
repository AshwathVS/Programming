class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) {
            return "";
        }
        return recursiveLCP(strs, 0, strs.size() - 1);
    }
    
    // 0, 5
    // 0, 2 and 3, 5
    // 0, 1 and 
    
    string recursiveLCP(vector<string>& strs, int i, int j) {
        if (i == j) {
            return strs[i];
        }
        else if (j - i == 1) {
            return getLCP(strs[i], strs[j]);
        } else {
            int mid = (i + j) / 2;
            return getLCP(recursiveLCP(strs, i, mid), recursiveLCP(strs, mid + 1, j));
        }
    }
    
    string getLCP(string s1, string s2) {
            string result = "";
            for(int i = 0; (i < s1.length() && i < s2.length()); i++) {
                if (s1[i] == s2[i]) {
                    result += s1[i];
                } else {
                    break;
                }
            }
            return result;
        }
    
    
};