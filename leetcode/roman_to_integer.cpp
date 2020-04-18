class Solution {
public:
    int romanToInt(string s) {
        map<char, int> valueStore;
        
        valueStore['I'] = 1;
        valueStore['V'] = 5;
        valueStore['X'] = 10;
        valueStore['L'] = 50;
        valueStore['C'] = 100;
        valueStore['D'] = 500;
        valueStore['M'] = 1000;
        
        int result = 0;
        int previousValue = INT_MAX;
        for (int i = 0; i < s.length(); i++) {
            int currentValue = valueStore[s[i]];
            int tmp = currentValue;
            if (currentValue > previousValue) {
                currentValue -= (2 * previousValue);
            }
            
            result += currentValue;
            previousValue = tmp;
        }
        
        return result;
    }
};