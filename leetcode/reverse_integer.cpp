class Solution {
public:
   int reverse(int n) {
        int result = 0, mod;
        int xx = INT_MAX / 10;
        int yy = INT_MIN / 10;
        while(n) {
            mod = n%10;

            if(result > xx || (result == xx && mod > 7)) return 0;
            if(result < yy || (result == yy && mod < -8)) return 0;

            result = result * 10 + mod;
            n=n/10;
        }

        return result;
    }
};
