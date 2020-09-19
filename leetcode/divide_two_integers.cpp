class Solution {
public:
    int divide(int dividend, int divisor) {
        int posres = (dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0);
        long long divid = abs((long long)dividend);
        long long divis = abs((long long)divisor);
        int res=0;

        while(divid >= divis) {
            int count=1;
            long long tmpd = divis;

            while((tmpd << 1) <= divid) {
                tmpd = tmpd << 1;
                count = count << 1;
            }

            divid -= tmpd;
            res += count;
        }

        if(posres) {
            if(res >= INT_MAX || res <= INT_MIN) return INT_MAX;
            else return (int) res;
        } else {
            if(res >= INT_MAX || res <= INT_MIN) return INT_MIN;
            else return (int) -res;
        }
    }

};