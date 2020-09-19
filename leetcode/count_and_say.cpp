class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) return "1";
        else {
            string xx = countAndSay(n-1);
            string res= "";

            int count=0;
            char prev=xx[0];
            for(char a : xx) {
                if(a == prev) count++;
                else {
                    res += to_string(count);
                    res += prev;
                    count = 1;
                }

                prev = a;
            }
            res += to_string(count);
            res += prev;

            return res;
        }
    }
};