class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> v;
        recurse(n, v, 0, 0, "");
        return v;
    }   
    
    void recurse(int n, vector<string>& v, int openCount, int closeCount, string result) {
        if(result.length() == 2*n) {
            v.push_back(result);
        }
        else {
            if(openCount < n) recurse(n, v, openCount + 1, closeCount, result + "(");
            if(closeCount < openCount) recurse(n, v, openCount, closeCount + 1, result + ")");
        }
    }
};

