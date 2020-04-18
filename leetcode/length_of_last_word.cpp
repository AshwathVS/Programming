class Solution {
public:
    int lengthOfLastWord(string s) {
        int j = s.length() - 1;
        if (j < 0) {
            return 0;
        }
        int counter = 0;
        while (j >= 0 && s[j] == ' ') {
            j--;
        }
        while (j >= 0 && s[j] != ' ') {
            counter++;
            j--;
        }
        return counter;
    }
};