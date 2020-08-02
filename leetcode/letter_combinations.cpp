class Solution {
public:
    vector<string> phone{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits != "") findAllCombinations(0, digits, "", res);
        return res;
    }
    
    void findAllCombinations(int index, string digits, string res, vector<string>& all) {
        if(index == digits.size()) all.push_back(res);
        else {
            int num = digits[index] - 48;
            for(char i: phone[num]) {
                findAllCombinations(index + 1, digits, res + i, all);
            }
        }
    }
};