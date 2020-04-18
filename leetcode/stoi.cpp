class Solution {
public:
    int myAtoi(string str) {
        bool neg = false;
        bool previousCharSign = false;
        bool previousCharNumber = false;
        int result = 0;
        for(int i = 0; i < str.length(); i++) {
            if (str[i] == 32) {
                if (previousCharSign || previousCharNumber) {
                    break;
                }
                continue;
            } else if(str[i] == 43) {
                if (previousCharSign || previousCharNumber) {
                    break;
                }
                previousCharSign = true;
                continue;  
            }
            else if (str[i] == 45) {
                if (previousCharSign || previousCharNumber) {
                    break;
                }
                previousCharSign = true;
                neg = true;
            } else if (str[i] >= 48 && str[i] <= 57) {
                previousCharNumber = true;
                int digit = str[i] - '0';
                // cout << "Digit: " << digit << endl;
                if (neg) {
                    if ((INT_MIN + digit) / 10 > result) {
                        // cout << "exitting because of limit prob" << endl;
                        return INT_MIN;
                    }
                } else {
                    if ((INT_MAX - digit) / 10 < result) {
                        // cout << "exitting because of limit prob" << endl;
                        return INT_MAX;
                    }
                }
                
                if (neg) {
                    result = (result * 10) - digit;
                } else {
                    result = (result * 10) + digit;
                }
            } else {
                if (previousCharSign || previousCharNumber) {
                    break;
                }
                return result;
            }
        }
        
        // if (neg == true) {
        //     result *= -1;
        // }
        return result;
}
};