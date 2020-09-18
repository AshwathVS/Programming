class Solution {
public:
    bool isPalindrome(int x) {
        int revertedNumber = 0;
        
        if(x < 0) return false;
        else if(x < 10) return true;
        else if(x%10 == 0) return false;
        else {
            while(revertedNumber < x) {
                int mod=x%10;
                x/=10;
                revertedNumber = revertedNumber * 10 + mod;
            }
            
            return revertedNumber == x || revertedNumber/10 == x;
        }
    }
};