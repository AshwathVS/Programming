class Solution {
public:
    double myPow(double x, int nn) {
        double n = (double) nn;
        if(n == 0) return 1;
        else if(n == 1) return x;
        else if(n == -1) return 1/x;
        else if(abs(x) == 1) {
            bool isNeg = (x == -1);

            if(nn % 2 == 0) return 1;
            else {
                if(isNeg) return -1;
                else return 1;
            }

        }
        else {
            double cnt = 1;
            bool isNeg = n < 0;
            double res = x;
            n = abs(n);

            while(cnt*2 <= n) {
                res*=res;
                cnt*=2;
            }

            while(cnt < n) {
                res*=x;
                cnt++;
            }


            if(isNeg) return 1/res;
            else return res;
        }
    }
};