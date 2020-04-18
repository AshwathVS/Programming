class Solution {
public:
    bool isHappy(int n) {
        int ctr = 0;
        while(ctr < 20) {
            int res = getSumOfSquaresOfDigits(n);
            if (res == 1) {
                return true;
            } else {
                n = res;
            }
            ctr++;
        }
        return false;
    }
    
    int getSumOfSquaresOfDigits(int n) {
        int sum = 0;
        while(n > 0) {
            int j = n % 10;
            sum += (j * j);
            n /= 10;
        }
        return sum;
    }
};