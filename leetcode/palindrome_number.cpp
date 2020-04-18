class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        } else if (x / 10 == 0) {
            return true;
        } else {
            return reverse(x) == x;
        }
    }
    
    int reverse(int n) {
        int result = 0, remainder = 0;
        
        while (n != 0) {
            remainder = n % 10;
            if (result > INT_MAX/10 || (result == INT_MAX/10 && remainder > 7)) return 0;
            if (result < INT_MIN/10 || (result == INT_MIN / 10 && remainder < -8)) return 0;
            result = result * 10 + remainder;
            n = n / 10;
        }
        return result;
    }
};