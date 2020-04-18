class Solution {
public:
    bool isValid(string s) {
        stack<char> check;
        bool isValid = true;
        for (int i = 0; i < s.length(); i++) {
            char currChar = s[i];
            if (isOpeningBrace(currChar)) {
                check.push(currChar);
            } else {
                if (check.size() > 0) {
                    if (check.top() == getMatchingParanthesis(currChar)) {
                        check.pop();
                    } else {
                        isValid = false;
                        break;
                    }
                } else {
                    isValid = false;
                    break;
                }
            }
        }
        
        
        if (check.size() > 0) {
            isValid = false;
        }
        
        return isValid;
    }
    
    bool isOpeningBrace(char c) {
        return c == '(' || c == '[' || c == '{';
    }
    
    char getMatchingParanthesis(char paranthesis) {
        if (paranthesis == '(') {
            return ')';
        } else if (paranthesis == ')') {
            return '(';
        } else if (paranthesis == '{') {
            return '}';
        } else if (paranthesis == '}') {
            return '{';
        } else if (paranthesis == '[') {
            return ']';
        } else {
            return '[';
        }
    }
};