class Solution {
public:
    string intToRoman(int num) {

        string res="";

        map<int, string> curr = {
                {1000, "M"},
                {900, "CM"},
                {500, "D"},
                {400, "CD"},
                {100, "C"},
                {90, "XC"},
                {50, "L"},
                {40, "XL"},
                {10, "X"},
                {9, "IX"},
                {5, "V"},
                {4, "IV"},
                {1, "I"}
        };

        for(int xx : {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1}) {
            while(num >= xx) {
                res += curr[xx];
                num -= xx;
            }
        }

        return res;
    }
};