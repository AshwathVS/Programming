class Solution {
public:
    int titleToNumber(string s) {
        int res = 0, tot = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            int _pow = pow(26, tot);
            res += (_pow * (s[i] - 64));
            tot++;
        }
        return res;
    }
};